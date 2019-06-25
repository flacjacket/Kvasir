/**************************************************************************
Copyright 2015 Odin Holmes
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
****************************************************************************/
#pragma once
#include "Mpl/Algorithm.hpp"
#include "Types.hpp"

#include "kvasir/mpl/mpl.hpp"

namespace Kvasir {
namespace Io{
    namespace Detail{
        template<typename T>
        struct IsPinLoaction : kvasir::mpl::false_ {};
        template<int Port, int Pin>
        struct IsPinLoaction<Register::PinLocation<Port,Pin>> : kvasir::mpl::true_ {};

        template<typename T, typename U>
        struct PinLocationLess;
        template<int PortL, int PinL, int PortR, int PinR>
        struct PinLocationLess<
            Register::PinLocation<PortL,PinL>,
            Register::PinLocation<PortR,PinR>>
            : kvasir::mpl::bool_<(PortL==PortR?PinL<PinR:PortL<PortR)>{};
        using PinLocationLessP = MPL::Template<PinLocationLess>;

        template<typename T>
        struct IsPort : kvasir::mpl::false_ {};
        template<PortAccess A, typename... Ts>
        struct IsPort<Port<A,Ts...>> : kvasir::mpl::true_ {};

        template<typename T>
        struct GetHwPort;
        template<int Port, int Pin>
        struct GetHwPort<Register::PinLocation<Port,Pin>> : kvasir::mpl::int_<Port>{};
        using GetHwPortP = MPL::Template<GetHwPort>;

        template<typename T, typename U>
        struct OnSamePort : kvasir::mpl::false_ {};
        template<int Port, int PinL, int PinR>
        struct OnSamePort<Register::PinLocation<Port,PinL>, Register::PinLocation<Port,PinR>> : kvasir::mpl::true_  {};
        using PortEqualP = MPL::Template<OnSamePort>;

        template<typename TList>
        using GetPortNumbersT = brigand::transform<MPL::UniqueT<MPL::SortT<TList,PinLocationLessP>, PortEqualP>, GetHwPortP>;

        template<typename T>
        struct IsSinglePort : kvasir::mpl::false_ {};
        template<PortAccess A, typename... Ts>
        struct IsSinglePort<Port<A,Ts...>> : kvasir::mpl::bool_<(MPL::Size<GetPortNumbersT<brigand::list<Ts...>>>::value == 1)>{};

        template<typename T>
        struct IsDistributedPort : kvasir::mpl::false_ {};
        template<PortAccess A, typename... Ts>
        struct IsDistributedPort<Port<A,Ts...>> : kvasir::mpl::bool_<(MPL::Size<GetPortNumbersT<brigand::list<Ts...>>>::value > 1)>{};

        template<typename T>
        struct GetAccess;
        template<PortAccess A, typename... Ts>
        struct GetAccess<Port<A,Ts...>> : MPL::Value<PortAccess, A> {};


    }
}
}
