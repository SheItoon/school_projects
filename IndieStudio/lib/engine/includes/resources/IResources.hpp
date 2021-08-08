/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** IResources.hpp
*/

#ifndef __SHIPWRECK_IRESOURCES_HPP__
#define __SHIPWRECK_IRESOURCES_HPP__

namespace sw
{

    class ITexture {
        public:
            virtual ~ITexture() = default;
    };

    class ISound {
        public:
            virtual ~ISound() = default;
    };

    class IFont {
        public:
            virtual ~IFont() = default;
    };

    class IModel {
        public:
            virtual ~IModel() = default;
    };
    class IMusic {
    public:
        virtual ~IMusic() = default;
    };

} // namespace sw

#endif // __SHIPWRECK_IRESOURCES_HPP__
