
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "Ros2ProjectSystemComponent.h"
#include "Ros2ProjectSampleComponent.h"

namespace Ros2Project
{
    class Ros2ProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(Ros2ProjectModule, "{0616E2E7-90AC-4C4F-82AD-77F9BC1610F4}", AZ::Module);
        AZ_CLASS_ALLOCATOR(Ros2ProjectModule, AZ::SystemAllocator);

        Ros2ProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                Ros2ProjectSystemComponent::CreateDescriptor(),
                Ros2ProjectSampleComponent::CreateDescriptor(),
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

AZ_DECLARE_MODULE_CLASS(Gem_Ros2Project, Ros2Project::Ros2ProjectModule)
