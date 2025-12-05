## Fixed-Point Arithmetic: Multiplication and Division

This section explains the logic behind the `operator*` and `operator/` implementations for the `Fixed` class. The core idea is to correctly manage the scaling factor (`2^FRACTIONAL_BITS`) inherent in fixed-point numbers.

### Multiplication (`operator*`)

When multiplying two fixed-point numbers, say `A` and `B`, where each is represented as `raw_value / 2^N` (with `N = FRACTIONAL_BITS`):

`A * B = (A_raw / 2^N) * (B_raw / 2^N) = (A_raw * B_raw) / (2^N * 2^N) = (A_raw * B_raw) / 2^(2N)`

The result `(A_raw * B_raw)` effectively has `2N` fractional bits. To convert this back to our standard `N` fractional bits format, we need to divide by `2^N`.

*   **Implementation:** `(this->fixedPoint * other.fixedPoint) >> FRACTIONAL_BITS`
    *   `this->fixedPoint * other.fixedPoint`: Performs the raw integer multiplication.
    *   `>> FRACTIONAL_BITS`: Right-shifts the result by `FRACTIONAL_BITS` (which is equivalent to dividing by `2^FRACTIONAL_BITS`), bringing the number back to the correct `N`-fractional-bit scale.
*   **`static_cast<long long>`:** The intermediate product `(this->fixedPoint * other.fixedPoint)` can exceed the capacity of a standard `int` (32-bit) if both `fixedPoint` values are large. Casting one of the operands to `long long` (64-bit) before multiplication ensures that the product is calculated in 64-bit space, preventing overflow.

### Division (`operator/`)

When dividing two fixed-point numbers, `A / B`:

`A / B = (A_raw / 2^N) / (B_raw / 2^N)`

If we simply perform `A_raw / B_raw`, we lose all fractional precision, as integer division truncates the result. To maintain precision and ensure the result is correctly scaled to `N` fractional bits:

*   **Strategy:** We need to effectively multiply the numerator `A_raw` by `2^N` *before* dividing by `B_raw`. This scales `A_raw` up, allowing the division to produce a more precise result that is already in the `N`-fractional-bit format.
*   **Implementation:** `(this->fixedPoint << FRACTIONAL_BITS) / other.fixedPoint`
    *   `this->fixedPoint << FRACTIONAL_BITS`: Left-shifts `this->fixedPoint` by `FRACTIONAL_BITS` (equivalent to multiplying by `2^FRACTIONAL_BITS`).
    *   `/ other.fixedPoint`: Divides the scaled numerator by the denominator.
*   **`static_cast<long long>`:** Similar to multiplication, left-shifting `this->fixedPoint` can cause an overflow if `this->fixedPoint` is large. Casting to `long long` first ensures the intermediate value fits.
*   **Division by Zero Check:** `if (other.fixedPoint == 0)`: Division by zero is an undefined operation and would cause a program crash. This check prevents it, printing an error and returning a default `Fixed` object.