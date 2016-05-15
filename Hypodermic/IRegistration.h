#pragma once

#include <functional>
#include <memory>
#include <unordered_map>


namespace Hypodermic
{

    class Container;
    class IRegistrationActivator;
    class TypeAliasKey;
    struct TypeInfo;


    class IRegistration
    {
    public:
        virtual ~IRegistration() {}

        virtual const TypeInfo& instanceType() const = 0;

        virtual const std::unordered_map< TypeAliasKey, std::function< std::shared_ptr< void >(const std::shared_ptr< void >&) > >& typeAliases() const = 0;

        virtual std::function< std::shared_ptr< void >(Container&) > getDependencyFactory(const TypeInfo& dependencyType) const = 0;

        virtual IRegistrationActivator& activator() = 0;
    };

} // namespace Hypodermic