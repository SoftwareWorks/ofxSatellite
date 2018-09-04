//
// Copyright (c) 2013 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:    MIT
//


#pragma once


#include <vector>
#include "SGP4.h"
#include "CoordTopocentric.h"
#include "CoordGeodetic.h"
#include "Observer.h"
#include "Util.h"
#include "Poco/DateTime.h"
#include "ofFileUtils.h"
#include "ofxGeo.h"


namespace ofx {
namespace Satellite {


class Satellite;


/// \brief A collection of utilities for satellite tasks.
class Utils
{
public:
    struct PassDetails
    {
        DateTime aos;
        DateTime los;
        double max_elevation;
    };

    static std::vector<Satellite> loadTLEFromFile(const std::string& filename);

    static std::vector<Satellite> loadTLEFromBuffer(const ofBuffer& buffer);

    static Geo::ElevatedCoordinate getPosition(const SGP4& satellite,
                                               const Poco::DateTime& time);

    static DateTime toDateTime(const Poco::DateTime& time);

    static Geo::ElevatedCoordinate toElevatedCoordinate(const CoordGeodetic& coord);

    static Observer toObserver(const Geo::ElevatedCoordinate& coordinate0);

    static double FindMaxElevation(const CoordGeodetic& user_geo,
                                   SGP4& sgp4,
                                   const DateTime& aos,
                                   const DateTime& los);

    static DateTime FindCrossingPoint(const CoordGeodetic& user_geo,
                                      SGP4& sgp4,
                                      const DateTime& initial_time1,
                                      const DateTime& initial_time2,
                                      bool finding_aos);


    static std::vector<PassDetails> GeneratePassList(const CoordGeodetic& user_geo,
                                                     SGP4& sgp4,
                                                     const DateTime& start_time,
                                                     const DateTime& end_time,
                                                     const int time_step);


};

} } // namespace ofx::Satellite
