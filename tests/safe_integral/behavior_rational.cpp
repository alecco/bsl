/// @copyright
/// Copyright (C) 2020 Assured Information Security, Inc.
///
/// @copyright
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// @copyright
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// @copyright
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.

#include <bsl/discard.hpp>
#include <bsl/safe_integral.hpp>
#include <bsl/ut.hpp>

namespace bsl
{
    /// <!-- description -->
    ///   @brief Used to execute the actual checks. We put the checks in this
    ///     function so that we can validate the tests both at compile-time
    ///     and at run-time. If a bsl::ut_check fails, the tests will either
    ///     fail fast at run-time, or will produce a compile-time error.
    ///
    /// <!-- inputs/outputs -->
    ///   @return Always returns bsl::exit_success.
    ///
    template<typename T>
    [[nodiscard]] constexpr auto
    tests() noexcept -> bsl::exit_code
    {
        bsl::ut_scenario{"eq"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(42)};
                bsl::safe_integral<T> const val2{static_cast<T>(42)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 == val2);
                };
            };
        };

        bsl::ut_scenario{"eq with a value"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(42)};
                T const val2{static_cast<T>(42)};    // NOLINT
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 == val2);
                };
            };

            bsl::ut_given{} = []() noexcept {
                T const val1{static_cast<T>(42)};    // NOLINT
                bsl::safe_integral<T> const val2{static_cast<T>(42)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 == val2);
                };
            };
        };

        bsl::ut_scenario{"ne"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(42)};
                bsl::safe_integral<T> const val2{static_cast<T>(23)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 != val2);
                };
            };
        };

        bsl::ut_scenario{"ne with a value"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(42)};
                T const val2{static_cast<T>(23)};    // NOLINT
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 != val2);
                };
            };

            bsl::ut_given{} = []() noexcept {
                T const val1{static_cast<T>(42)};    // NOLINT
                bsl::safe_integral<T> const val2{static_cast<T>(23)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 != val2);
                };
            };
        };

        bsl::ut_scenario{"lt"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(23)};
                bsl::safe_integral<T> const val2{static_cast<T>(42)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 < val2);
                };
            };
        };

        bsl::ut_scenario{"lt with a value"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(23)};
                T const val2{static_cast<T>(42)};    // NOLINT
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 < val2);
                };
            };

            bsl::ut_given{} = []() noexcept {
                T const val1{static_cast<T>(23)};    // NOLINT
                bsl::safe_integral<T> const val2{static_cast<T>(42)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 < val2);
                };
            };
        };

        bsl::ut_scenario{"gt"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(42)};
                bsl::safe_integral<T> const val2{static_cast<T>(23)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 > val2);
                };
            };
        };

        bsl::ut_scenario{"gt with a value"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(42)};
                T const val2{static_cast<T>(23)};    // NOLINT
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 > val2);
                };
            };

            bsl::ut_given{} = []() noexcept {
                T const val1{static_cast<T>(42)};    // NOLINT
                bsl::safe_integral<T> const val2{static_cast<T>(23)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 > val2);
                };
            };
        };

        bsl::ut_scenario{"lteq"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(23)};
                bsl::safe_integral<T> const val2{static_cast<T>(42)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 <= val2);
                };
            };
        };

        bsl::ut_scenario{"lteq with a value"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(23)};
                T const val2{static_cast<T>(42)};    // NOLINT
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 <= val2);
                };
            };

            bsl::ut_given{} = []() noexcept {
                T const val1{static_cast<T>(23)};    // NOLINT
                bsl::safe_integral<T> const val2{static_cast<T>(42)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 <= val2);
                };
            };
        };

        bsl::ut_scenario{"gteq"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(42)};
                bsl::safe_integral<T> const val2{static_cast<T>(23)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 > val2);
                };
            };
        };

        bsl::ut_scenario{"gteq with a value"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_integral<T> const val1{static_cast<T>(42)};
                T const val2{static_cast<T>(23)};    // NOLINT
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 >= val2);
                };
            };

            bsl::ut_given{} = []() noexcept {
                T const val1{static_cast<T>(42)};    // NOLINT
                bsl::safe_integral<T> const val2{static_cast<T>(23)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(val1 >= val2);
                };
            };
        };

        return bsl::ut_success();
    }
}

/// <!-- description -->
///   @brief Main function for this unit test. If a call to bsl::ut_check() fails
///     the application will fast fail. If all calls to bsl::ut_check() pass, this
///     function will successfully return with bsl::exit_success.
///
/// <!-- inputs/outputs -->
///   @return Always returns bsl::exit_success.
///
[[nodiscard]] auto
main() noexcept -> bsl::exit_code
{
    static_assert(bsl::tests<bsl::int8>() == bsl::ut_success());
    static_assert(bsl::tests<bsl::int16>() == bsl::ut_success());
    static_assert(bsl::tests<bsl::int32>() == bsl::ut_success());
    static_assert(bsl::tests<bsl::int64>() == bsl::ut_success());
    static_assert(bsl::tests<bsl::uint8>() == bsl::ut_success());
    static_assert(bsl::tests<bsl::uint16>() == bsl::ut_success());
    static_assert(bsl::tests<bsl::uint32>() == bsl::ut_success());
    static_assert(bsl::tests<bsl::uint64>() == bsl::ut_success());
    static_assert(bsl::tests<bsl::uintmx>() == bsl::ut_success());

    bsl::discard(bsl::tests<bsl::int8>());
    bsl::discard(bsl::tests<bsl::int16>());
    bsl::discard(bsl::tests<bsl::int32>());
    bsl::discard(bsl::tests<bsl::int64>());
    bsl::discard(bsl::tests<bsl::uint8>());
    bsl::discard(bsl::tests<bsl::uint16>());
    bsl::discard(bsl::tests<bsl::uint32>());
    bsl::discard(bsl::tests<bsl::uint64>());
    bsl::discard(bsl::tests<bsl::uintmx>());

    return bsl::ut_success();
}
