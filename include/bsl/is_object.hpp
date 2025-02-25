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
/// @file is_object.hpp
///

#ifndef BSL_IS_OBJECT_HPP
#define BSL_IS_OBJECT_HPP

#include "bsl/bool_constant.hpp"    // IWYU pragma: export
#include "bsl/disjunction.hpp"
#include "bsl/is_array.hpp"
#include "bsl/is_class.hpp"
#include "bsl/is_scalar.hpp"
#include "bsl/is_union.hpp"

namespace bsl
{
    /// @class bsl::is_object
    ///
    /// <!-- description -->
    ///   @brief If the provided type is an object type, provides the member
    ///     constant value equal to true. Otherwise the member constant value
    ///     is false.
    ///   @include example_is_object_overview.hpp
    ///
    /// <!-- template parameters -->
    ///   @tparam T the type to query
    ///
    template<typename T>
    class is_object final :
        public bool_constant<
            disjunction<is_scalar<T>, is_array<T>, is_union<T>, is_class<T>>::value>
    {};
}

#endif
