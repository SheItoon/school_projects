/*
** EPITECH PROJECT, 2021
** Transform.hpp
** File description:
** Transform.hpp
*/

#ifndef TRASNFORM_HPP
#define TRASNFORM_HPP

#include "SW/Components.hpp"
#include "utils/matrix.hpp"
#include "utils/vector3.hpp"

namespace ray
{
    class Transform :
            public sw::Component
    {

    private:
        sw::Vector3f m_position;
        sw::Vector3f m_globalPosition;
        sw::Vector3f m_scale;
        sw::Vector3f m_globalScale;
        float m_angle;
        sw::Vector3f m_rotation;
        sw::Vector3f m_globalRotation;

        //sw::Vector2f m_position_origin;

        mutable sw::Matrixf m_matrix;
        mutable sw::Matrixf m_globalMatrix;
        //mutable sf::Transform m_sfTransform;
        //mutable sf::Transform m_globalSfTransform;
        mutable bool m_need_update;
        mutable bool m_global_need_update;

        void needUpdate() {
            m_need_update = true;
            m_global_need_update = true;
        }
        void notNeedUpdate() {
            m_need_update = false;
            m_global_need_update = false;
        }

        ///////////////////////////////////////////////////////////////////
        ///
        /// Update the matrix.
        ///
        /// @warning The const is just to can use it in get method,
        /// It's modify m_matrix variable.
        ///
        /// Thanks to this, we can reduce the calculations to what
        /// is strictly necessary.
        //
        void updateMatrix() const;
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Update the sfTransform.
        ///
        /// @warning The const is just to can use it in get method,
        /// It's modify m_sfTransform variable.
        ///
        /// Thanks to this, we can reduce the calculations to what
        /// is strictly necessary.
        //
        void updateSfTransform() const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Update the global sfTransform.
        ///
        /// @warning The const is just to can use it in get method,
        /// It's modify m_sfTransform variable.
        ///
        /// Thanks to this, we can reduce the calculations to what
        /// is strictly necessary.
        //
        void updateGlobalSfTransform() const;
        //
        ///////////////////////////////////////////////////////////////////

    public:
        ///////////////////////////////////////////////////////////////////
        ///
        /// Check if the Matrix need to be update.
        //
        bool checkUpdate() const;
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Initialize a Transform Component attached to the given Entity.
        ///
        /// @param engine The Engine data.
        /// @param entity The Entity to wich the Transform Component will
        /// be attached.
        ///
        Transform(sw::Entity& entityRef);
        ///
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Set the position of a Transform Component.
        /// The default position of a Transform Component is (0, 0).
        ///
        /// @warning This function overwrites the actual position.
        /// @see move() to add to the current position.
        ///
        /// @param position New position.
        //
        void setPosition(const sw::Vector3f& position);
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Set the position of a Transform Component.
        /// The default position of a Transform Component is (0, 0).
        ///
        /// @warning This function overwrites the actual position.
        /// @see move() to add to the current position.
        ///
        /// @param x X coordinate of the new position.
        /// @param y Y coordinate of the new position.
        //
        void setPosition(float x, float y, float z = 0);
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Move a Transform Component
        ///
        /// @warning This function adds to the current position.
        /// @see setPosition to overwrite the actual position.
        ///
        /// @param offset Add to the actual position of
        /// the Transform Component.
        //
        void move(const sw::Vector3f& position);
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Move a Transform Component.
        ///
        /// @warning This function adds to the current position.
        /// @see setPosition to overwrite the actual position.
        ///
        /// @param x X offset.
        /// @param y Y offset.
        //
        void move(float x, float y, float z = 0);
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the position of a Transform Component.
        //
        const sw::Vector3f& getPosition() const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the globale position of a Transform Component.
        //
        const sw::Vector3f& getGlobalPosition() const;
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Set the scalation of a Transform Component.
        /// The default scalation of a Transform Component is (1, 1).
        ///
        /// @warning This function overwrites the actual scalation.
        /// @see scale() to add to the current scalation.
        ///
        /// @param scale New scalation.
        //
        void setScale(const sw::Vector3f& scale);
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Set the scalation of a Transform Component.
        /// The default scalation of a Transform Component is (1, 1).
        ///
        /// @warning This function overwrites the actual scalation.
        /// @see scale() to add to the current scalation.
        ///
        /// @param x New horizontal scale factor.
        /// @param y New vertical scale factor.
        //
        void setScale(float x, float y, float z = 0);
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Scale the Transform Component.
        ///
        /// @warning This function multiplies the current scale of
        /// the Transform Component.
        /// @see setScale() to overwrite the actual scalation.
        ///
        /// @param scale Scale factor.
        //
        void scale(const sw::Vector3f& scale);
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Scale the Transform Component.
        ///
        /// @warning This function multiplies the current scale of
        /// the Transform Component.
        /// @see setScale() to overwrite the actual scalation.
        ///
        /// @param x Horizontal scale factor.
        /// @param y Vertical scale factor.
        //
        void scale(float x, float y, float z = 0);
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the scalation of a Transform Component.
        //
        const sw::Vector3f& getScale() const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the global scalation of a Transform Component.
        //
        const sw::Vector3f& getGlobalScale() const;
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Set the orientation of the Transform Component.
        /// The default rotation of a Transform Component is 0.
        ///
        /// @warning This function completely overwrites
        /// the previous rotation.
        /// @see rotate() to add an angle on the previous rotation.
        //
        void setRotation(float angle, float rotationX = 0, float rotationY = 1, float rotationZ = 0);
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Rotate the Transform Component.
        ///
        /// @warning This function adds to the current rotation of
        /// the Transform Component.
        /// @see setRotation() to overwrite the actual orientation.
        //
        void rotate(float angle, float rotationX = 0, float rotationY = 1, float rotationZ = 0);
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the orientation of the Transform Component in degree.
        //
        sw::Vector3f getRotation() const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the orientation of the Transform Component in degree.
        //
        float getAngle() const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the orientation of the Transform Component in radiant.
        //
        sw::Vector3f getRadianRotation() const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the global orientation of the Transform Component in degree.
        //
        sw::Vector3f getGlobalRotation() const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the global orientation of the Transform Component in radiant.
        //
        sw::Vector3f getGlobalRadianRotation() const;
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the matrix of the Transform Component.
        //
        const sw::Matrixf& getMatrix() const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the global matrix of the Transform Component.
        //
        const sw::Matrixf& getGlobalMatrix() const;
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the sfTransform of the Transform Component.
        //
        //const sf::Transform& getTransform() const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Get the sfTransform of the Transform Component.
        //
        //const sf::Transform& getGlobalTransform() const;
        //
        ///////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////
        ///
        /// Return the position of the given point, transform by
        /// the Transform Component.
        ///
        /// @param point The point to transform.
        //
        const sw::Vector3f getTransformPoint(const sw::Vector3f& point) const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Return the position of the given point, transform by
        /// the Transform Component.
        ///
        /// @param x X coordinate of the point to transform.
        /// @param y Y coordinate of the point to transform.
        //
        const sw::Vector3f getTransformPoint(float x, float y, float z = 1) const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Return the position of the given point, transform by
        /// the Transform Component.
        ///
        /// @param point The point to transform.
        //
        const sw::Vector3f getGlobalTransformPoint(const sw::Vector3f& point) const;
        //
        ///////////////////////////////////////////////////////////////////
        ///
        /// Return the position of the given point, transform by
        /// the Transform Component.
        ///
        /// @param x X coordinate of the point to transform.
        /// @param y Y coordinate of the point to transform.
        //
        const sw::Vector3f getGlobalTransformPoint(float x, float y, float z = 1) const;
        //
        ///////////////////////////////////////////////////////////////////

    }; // class Transform
} // namespace ray

#endif //TRASNFORM_HPP
