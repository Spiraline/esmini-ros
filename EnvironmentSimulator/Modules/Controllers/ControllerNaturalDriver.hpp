/*
 * esmini - Environment Simulator Minimalistic
 * https://github.com/esmini/esmini
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) partners of Simulation Scenarios
 * https://sites.google.com/view/simulationscenarios
 */

#pragma once

#include <string>
#include "Controller.hpp"
#include "Entities.hpp"
#include "vehicle.hpp"

#define CONTROLLER_NATURAL_DRIVER_TYPE_NAME "NaturalDriver"

namespace scenarioengine
{
    class ControllerNaturalDriver : public Controller
    {
    public:
        ControllerNaturalDriver(InitArgs* args);

        static const char* GetTypeNameStatic()
        {
            return CONTROLLER_NATURAL_DRIVER_TYPE_NAME;
        }
        virtual const char* GetTypeName()
        {
            return GetTypeNameStatic();
        }
        static int GetTypeStatic()
        {
            return CONTROLLER_TYPE_NATURAL_DRIVER;
        }
        virtual int GetType()
        {
            return GetTypeStatic();
        }

        void Init();
        void InitPostPlayer();
        void Step(double timeStep);
        int  Activate(ControlActivationMode lat_activation_mode,
                      ControlActivationMode long_activation_mode,
                      ControlActivationMode light_activation_mode,
                      ControlActivationMode anim_activation_mode);
        void ReportKeyEvent(int key, bool down);
        void SetSetSpeed(double setSpeed)
        {
            setSpeed_ = setSpeed;
        }

    private:
        vehicle::Vehicle vehicle_;
        bool             active_;
        double           timeGap_;  // target headway time
        double           setSpeed_;
        double           lateralDist_;
        double           currentSpeed_;
        bool             setSpeedSet_;
        bool             virtual_;
    };

    Controller* InstantiateNaturalDriver(void* args);
}  // namespace scenarioengine