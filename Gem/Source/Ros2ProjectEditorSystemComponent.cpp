
#include <AzCore/Serialization/SerializeContext.h>
#include "Ros2ProjectEditorSystemComponent.h"

namespace Ros2Project
{
    void Ros2ProjectEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<Ros2ProjectEditorSystemComponent, Ros2ProjectSystemComponent>()
                ->Version(0);
        }
    }

    Ros2ProjectEditorSystemComponent::Ros2ProjectEditorSystemComponent() = default;

    Ros2ProjectEditorSystemComponent::~Ros2ProjectEditorSystemComponent() = default;

    void Ros2ProjectEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("Ros2ProjectEditorService"));
    }

    void Ros2ProjectEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("Ros2ProjectEditorService"));
    }

    void Ros2ProjectEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void Ros2ProjectEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void Ros2ProjectEditorSystemComponent::Activate()
    {
        Ros2ProjectSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void Ros2ProjectEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        Ros2ProjectSystemComponent::Deactivate();
    }

} // namespace Ros2Project
