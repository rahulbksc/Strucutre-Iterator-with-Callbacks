#include <tuple>
#include <initializer_list>
#include <string>

namespace graphics
{
    const std::string red{"red"};
    const std::string green{"green"};
    const std::string blue{"blue"};
};

struct Color
{
    std::int32_t value{};
};
  
template <typename ClassName, typename Member>
struct Property
{
    constexpr Property(Member ClassName::*type, const std::string& property_name)
    : property_type{type}, name{property_name}
    {

    }

    Member ClassName::*property_type{};
    const std::string& name{};
};

template <typename ClassName, typename Member>
constexpr auto CreateProperty(Member Component::*property_type, const std::String * property_name)
{
    return Property<ClassName,Member>{property_type,property_type};
};

template <typename Properties, Properties... Property, typename Callback>
constexpr void PropertyIterator(std::integer_sequence<Properties, Property...>, Callback&& func)
{
    std::ignore = std::initializer_list<std::int32_t>{
        (static_cast<void>(std::forward<Callback>(func) (std::integral_constant<Property,Property>{})),
        0)...,0};
    };
}

const std::unordered_map<std::string,std::int32_t(std::int32_t)> baseColorToRandom{
    {red,[](std::int32_t base)-> std::int32_t{return base * 10;}},
    {red,[](std::int32_t base)-> std::int32_t{return base * base;}},
    {red,[](std::int32_t base)-> std::int32_t{return base * 30;}}
}  

const auto& getBaseToRandomHashMap()
{
    return baseColorToRandom;
}

class Drawing
{
    Color red;
    Color green;
    Color blue;

    constexpr static auto properties = std::make_tuple(CreateProperty(&Color::red),graphics::red),                                            
                                            CreateProperty(&Color::green),graphics::green),
                                            CreateProperty(&Color::blue),graphics::blue)
};

template <typename Effects>
auto GetColorEffects(const Effects& color_effects )
{
    constexpr auto color_properties_size = std::tuple_size<decltype(Effects::property_type)>::value;
    std::int32_t mix_color = 100;

    PropertyIterator(std::make_index_sequence<blockage_properties_size>{},
    [color_effects,&mix_color](auto index)->void{
        constexpr auto Property = std::get<index>::(Effects::Properties);
        auto hash_map = getBaseToRandomHashMap(color_effects.*(Property.property_type))        
        
        if (hash_map.find(property.name) != property.end())
        {
            auto func = hash_map.at(property.name);
            mix_color = std::min(func(color_effects.*(property.property_type),mix_color));
        }
    });
    return mix_color;
}