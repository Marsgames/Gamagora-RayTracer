//
//  Misc.hpp
//  Synthese2
//
//  Created by Raphaël Daumas on 31/03/2019.
//  Copyright © 2019 Marsgames. All rights reserved.
//

#pragma once

#include <iostream>
#include <Sphere.hpp>
#include <vector>
#include <Camera.hpp>
#include <Vector3.hpp>
#include <Pixel.hpp>
#include <Light.hpp>

using std::vector;

class Scene
{
private:
    using Image = vector<Pixel>;
    
    Light* m_light;
    vector<Sphere>* m_spheres;
    double facteurLumiere{0.002};
    
    void ClearImage (Image& imageArray, const Camera& ecran);
    void ImageFromArray(const Image& pixelsArray, const string source, const string nomImage, const Camera& ecran);
    
public:
    Scene(Light& light, vector<Sphere>& spheres) :
    m_light{&light},
    m_spheres{&spheres}
    {};
    
    void LaunchThreads(const int nbImages, const Camera& ecran, const Vector3& directionLight);
    void GenerateImages(const int firstImage, const int lastImage, Camera& ecran, const Vector3& MoveLightDirection);
};
