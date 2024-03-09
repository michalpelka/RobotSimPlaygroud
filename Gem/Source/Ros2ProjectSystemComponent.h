/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/Component/Component.h>

#include <Ros2Project/Ros2ProjectBus.h>

namespace Ros2Project
{
    class Ros2ProjectSystemComponent
        : public AZ::Component
        , protected Ros2ProjectRequestBus::Handler
    {
    public:
        AZ_COMPONENT(Ros2ProjectSystemComponent, "{F51F9BF2-10B5-4822-A93C-5B18A4E7E6C3}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Ros2ProjectSystemComponent();
        ~Ros2ProjectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Ros2ProjectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
