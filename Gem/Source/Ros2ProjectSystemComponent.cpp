

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "Ros2ProjectSystemComponent.h"

namespace Ros2Project
{
    void Ros2ProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<Ros2ProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<Ros2ProjectSystemComponent>("Ros2Project", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void Ros2ProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("Ros2ProjectService"));
    }

    void Ros2ProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("Ros2ProjectService"));
    }

    void Ros2ProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Ros2ProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    Ros2ProjectSystemComponent::Ros2ProjectSystemComponent()
    {
        if (Ros2ProjectInterface::Get() == nullptr)
        {
            Ros2ProjectInterface::Register(this);
        }
    }

    Ros2ProjectSystemComponent::~Ros2ProjectSystemComponent()
    {
        if (Ros2ProjectInterface::Get() == this)
        {
            Ros2ProjectInterface::Unregister(this);
        }
    }

    void Ros2ProjectSystemComponent::Init()
    {
    }

    void Ros2ProjectSystemComponent::Activate()
    {
        Ros2ProjectRequestBus::Handler::BusConnect();
    }

    void Ros2ProjectSystemComponent::Deactivate()
    {
        Ros2ProjectRequestBus::Handler::BusDisconnect();
    }
}
