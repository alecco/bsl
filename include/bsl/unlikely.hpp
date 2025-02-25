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
///
/// @file unlikely.hpp
///

#ifndef BSL_UNLIKELY_HPP
#define BSL_UNLIKELY_HPP

namespace bsl
{
    /// <!-- description -->
    ///   @brief Implements a wrapper around __builtin_expect
    ///   @include example_unlikely_overview.hpp
    ///
    /// <!-- inputs/outputs -->
    ///   @tparam ARG the type that define the provided argument
    ///   @param pudm_udm_a the arguments check
    ///   @return Returns the boolean output of __builtin_expect
    ///
    template<typename ARG>
    [[nodiscard]] constexpr auto
    unlikely(ARG &&pudm_udm_a) noexcept -> bool
    {
        return 0L != __builtin_expect(!!(pudm_udm_a), 0L);
    }

    /// <!-- description -->
    ///   @brief Used to tell the user during compile-time that an
    ///     invalid argument has been provided to the code.
    ///
    inline void
    unlikely_invalid_argument_failure() noexcept
    {}

    /// <!-- description -->
    ///   @brief Used to tell the user during compile-time that a
    ///     precondition check has failed.
    ///
    inline void
    unlikely_precondition_failure() noexcept
    {}
}

#endif
