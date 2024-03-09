
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <Ros2ProjectSystemComponent.h>

namespace Ros2Project
{
    class Ros2ProjectModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(Ros2ProjectModuleInterface, "{B097CB7E-6FB0-44F3-8052-5541EF92AB9F}", AZ::Module);
        AZ_CLASS_ALLOCATOR(Ros2ProjectModuleInterface, AZ::SystemAllocator, 0);

        Ros2ProjectModuleInterface()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                Ros2ProjectSystemComponent::CreateDescriptor(),
                });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<Ros2ProjectSystemComponent>(),
            };
        }
    };
}// namespace Ros2Project
