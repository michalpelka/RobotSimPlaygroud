
#include <Ros2ProjectModuleInterface.h>
#include "Ros2ProjectEditorSystemComponent.h"

#include "Ros2ProjectSampleComponent.h"
namespace Ros2Project
{
    class Ros2ProjectEditorModule
        : public Ros2ProjectModuleInterface
    {
    public:
        AZ_RTTI(Ros2ProjectEditorModule, "{0616E2E7-90AC-4C4F-82AD-77F9BC1610F4}", Ros2ProjectModuleInterface);
        AZ_CLASS_ALLOCATOR(Ros2ProjectEditorModule, AZ::SystemAllocator, 0);

        Ros2ProjectEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                Ros2ProjectEditorSystemComponent::CreateDescriptor(),
                Ros2ProjectSampleComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<Ros2ProjectEditorSystemComponent>(),
            };
        }
    };
}// namespace Ros2Project

AZ_DECLARE_MODULE_CLASS(Gem_Ros2Project, Ros2Project::Ros2ProjectEditorModule)
