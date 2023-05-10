

#ifndef THREEPP_DECALGEOMETRY_HPP
#define THREEPP_DECALGEOMETRY_HPP

#include "threepp/core/BufferGeometry.hpp"

namespace threepp {

    class Mesh;
    class Euler;

    class DecalGeometry: public BufferGeometry {

    public:
        [[nodiscard]] std::string type() const override {

            return "DecalGeometry";
        }

        static std::shared_ptr<DecalGeometry> create(const Mesh& mesh, const Vector3& position, const Euler& orientation, const Vector3& size) {

            return std::shared_ptr<DecalGeometry>(new DecalGeometry(mesh, position, orientation, size));
        }

    private:
        DecalGeometry(const Mesh& mesh, const Vector3& position, const Euler& orientation, const Vector3& size);
    };

}// namespace threepp

#endif//THREEPP_DECALGEOMETRY_HPP
