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
/// @file has_unique_object_representations.hpp
///

#ifndef BSL_HAS_UNIQUE_OBJECT_REPRESENTATION_HPP
#define BSL_HAS_UNIQUE_OBJECT_REPRESENTATION_HPP

#include "bsl/bool_constant.hpp"    // IWYU pragma: export
#include "bsl/remove_cvext.hpp"

namespace bsl
{
    /// @class bsl::has_unique_object_representations
    ///
    /// <!-- description -->
    ///   @brief If the provided type is a class type, provides the member
    ///     constant value equal to true. Otherwise the member constant value
    ///     is false.
    ///   @include example_has_unique_object_representations_overview.hpp
    ///
    /// <!-- template parameters -->
    ///   @tparam T the type to query
    ///
    template<typename T>
    class has_unique_object_representations final :
        public bool_constant<__has_unique_object_representations(remove_cvext_t<T>)>
    {};
}

#endif
