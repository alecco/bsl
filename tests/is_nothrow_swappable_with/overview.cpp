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

#include <bsl/is_nothrow_swappable_with.hpp>
#include <bsl/ut.hpp>

namespace bsl
{
    void swap(bsl::safe_u16, bsl::safe_u16) noexcept;
    void swap(bsl::safe_u32, bsl::safe_u32) noexcept = delete;
    // NOLINTNEXTLINE(bsl-function-noexcept)
    void swap(bsl::safe_u64, bsl::safe_u64);
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
    static_assert(bsl::is_nothrow_swappable_with<bsl::safe_u16, bsl::safe_u16>::value);
    static_assert(!bsl::is_nothrow_swappable_with<bsl::safe_u32, bsl::safe_u32>::value);
    static_assert(!bsl::is_nothrow_swappable_with<bsl::safe_u64, bsl::safe_u64>::value);
    static_assert(!bsl::is_nothrow_swappable_with<bsl::safe_u32, bsl::safe_u64>::value);

    return bsl::ut_success();
}
