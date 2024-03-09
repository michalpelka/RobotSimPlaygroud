/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Ros2Project
{
    class Ros2ProjectRequests
    {
    public:
        AZ_RTTI(Ros2ProjectRequests, "{ABDB79AD-8593-49EF-81E7-330C418A6E84}");
        virtual ~Ros2ProjectRequests() = default;
        // Put your public methods here
    };

    class Ros2ProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Ros2ProjectRequestBus = AZ::EBus<Ros2ProjectRequests, Ros2ProjectBusTraits>;
    using Ros2ProjectInterface = AZ::Interface<Ros2ProjectRequests>;

} // namespace Ros2Project
