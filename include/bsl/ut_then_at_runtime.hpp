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
/// @file ut_then_at_runtime.hpp
///

#ifndef BSL_UT_THEN_AT_RUNTIME_HPP
#define BSL_UT_THEN_AT_RUNTIME_HPP

#include "bsl/cstr_type.hpp"
#include "bsl/discard.hpp"
#include "bsl/is_constant_evaluated.hpp"
#include "bsl/touch.hpp"

namespace bsl
{
    /// @class bsl::ut_then_at_runtime
    ///
    /// <!-- description -->
    ///   @brief Defines the expected "result" of a unit test scenario.
    ///
    class ut_then_at_runtime final
    {
    public:
        /// <!-- description -->
        ///   @brief Default constructor
        ///
        /// <!-- inputs/outputs -->
        ///   @param name the name of the scenario (i.e., test case)
        ///
        explicit constexpr ut_then_at_runtime(cstr_type const name = "ignored") noexcept
        {
            bsl::discard(name);
        }

        /// <!-- description -->
        ///   @brief Executes a lambda function as the body of the
        ///     "then" portion of the scenario.
        ///
        /// <!-- inputs/outputs -->
        ///   @tparam FUNC_T the type of lambda being executed
        ///   @param mut_func the lambda being executed
        ///   @return Returns a reference to the ut_then_at_runtime.
        ///
        template<typename FUNC_T>
        [[maybe_unused]] constexpr auto
        operator=(FUNC_T &&mut_func) &&noexcept -> ut_then_at_runtime &
        {
            if (!is_constant_evaluated()) {
                mut_func();
            }
            else {
                bsl::touch();
            }

            return *this;
        }

        /// <!-- description -->
        ///   @brief Destroyes a previously created bsl::ut_then_at_runtime
        ///
        constexpr ~ut_then_at_runtime() noexcept = default;

        /// <!-- description -->
        ///   @brief copy constructor
        ///
        /// <!-- inputs/outputs -->
        ///   @param o the object being copied
        ///
        constexpr ut_then_at_runtime(ut_then_at_runtime const &o) noexcept = default;

        /// <!-- description -->
        ///   @brief move constructor
        ///
        /// <!-- inputs/outputs -->
        ///   @param mut_o the object being moved
        ///
        constexpr ut_then_at_runtime(ut_then_at_runtime &&mut_o) noexcept = default;

        /// <!-- description -->
        ///   @brief copy assignment
        ///
        /// <!-- inputs/outputs -->
        ///   @param o the object being copied
        ///   @return a reference to *this
        ///
        [[maybe_unused]] constexpr auto operator=(ut_then_at_runtime const &o) &noexcept
            -> ut_then_at_runtime & = default;

        /// <!-- description -->
        ///   @brief move assignment
        ///
        /// <!-- inputs/outputs -->
        ///   @param mut_o the object being moved
        ///   @return a reference to *this
        ///
        [[maybe_unused]] constexpr auto operator=(ut_then_at_runtime &&mut_o) &noexcept
            -> ut_then_at_runtime & = default;
    };
}

#endif
