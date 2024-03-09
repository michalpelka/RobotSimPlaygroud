
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Ros2ProjectSystemComponent.h>

namespace Ros2Project
{
    /// System component for Ros2Project editor
    class Ros2ProjectEditorSystemComponent
        : public Ros2ProjectSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = Ros2ProjectSystemComponent;
    public:
        AZ_COMPONENT(Ros2ProjectEditorSystemComponent, "{D09279C0-FFAF-4C0B-9821-0823EBBB006B}", BaseSystemComponent);
        static void Reflect(AZ::ReflectContext* context);

        Ros2ProjectEditorSystemComponent();
        ~Ros2ProjectEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace Ros2Project
