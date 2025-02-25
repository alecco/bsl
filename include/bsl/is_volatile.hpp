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
/// @file is_volatile.hpp
///

#ifndef BSL_IS_VOLATILE_HPP
#define BSL_IS_VOLATILE_HPP

#include "bsl/always_false.hpp"
#include "bsl/false_type.hpp"
#include "bsl/integral_constant.hpp"    // IWYU pragma: export
#include "bsl/true_type.hpp"

namespace bsl
{
    /// @class bsl::is_volatile
    ///
    /// <!-- description -->
    ///   @brief If the provided type is qualified as volatile, provides the
    ///     member constant value equal to true. Otherwise the member constant
    ///     value is false.
    ///
    /// <!-- notes -->
    ///   @note "volatile" is not supported by the BSL as it is not compliant
    ///     with AUTOSAR. We only provide this function so that it can be used
    ///     to detect if volatile is used in order to throw a compilation
    ///     error. Do not use "volatile" with the BSL.
    ///
    /// <!-- template parameters -->
    ///   @tparam T the type to query
    ///
    template<typename T>
    class is_volatile final : public false_type
    {};

    /// @cond doxygen off

    template<typename T>
    class is_volatile<T volatile> final : public true_type
    {
        static_assert(always_false<T>(), "volatile not supported");
    };

    /// @endcond doxygen on
}

#endif
