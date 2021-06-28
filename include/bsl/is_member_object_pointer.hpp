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
/// @file is_member_object_pointer.hpp
///

#ifndef BSL_IS_MEMBER_OBJECT_POINTER_HPP
#define BSL_IS_MEMBER_OBJECT_POINTER_HPP

#include "is_member_function_pointer.hpp"
#include "is_member_pointer.hpp"

namespace bsl
{
    namespace details
    {
        /// <!-- description -->
        ///   @brief Checks if a type "T" is a member object pointer and if so,
        ///     returns true, otherwise returns false.
        ///
        /// <!-- inputs/outputs -->
        ///   @tparam T the type to query
        ///   @return If "T" is a member object pointer, returns true,
        ///     otherwise returns false.
        ///
        template<typename T>
        [[nodiscard]] constexpr auto
        check_is_member_object_pointer() noexcept -> bool
        {
            if constexpr (bsl::is_member_function_pointer<T>::value) {
                return false;
            }

            return bsl::is_member_pointer<T>::value;
        }
    }

    /// @class bsl::is_member_object_pointer
    ///
    /// <!-- description -->
    ///   @brief If the provided type is a member object pointer type (taking
    ///     into account const qualifications), provides the member constant
    ///     value equal to true. Otherwise the member constant value is false.
    ///   @include example_is_member_object_pointer_overview.hpp
    ///
    /// <!-- template parameters -->
    ///   @tparam T the type to query
    ///
    template<typename T>
    class is_member_object_pointer final :    // --
        public bool_constant<details::check_is_member_object_pointer<T>()>
    {};
}

#endif
