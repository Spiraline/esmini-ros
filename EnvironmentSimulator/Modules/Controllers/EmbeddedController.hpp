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
#include "CommonMini.hpp"
#include "OSCProperties.hpp"
#include "Parameters.hpp"
#include "Controller.hpp"

#define CONTROLLER_BASE_TYPE_NAME "ControllerClass"
#define CONTROLLER_BASE_TYPE_ID   -1

namespace scenarioengine
{
    // Forward declarations
    class ScenarioPlayer;
    class ScenarioGateway;
    class ScenarioEngine;
    class Entities;
    class Object;

namespace controller
{
typedef struct
{
    std::string      name;
    std::string      type;
    OSCProperties*   properties;
    Entities*        entities;
    ScenarioGateway* gateway;
    Parameters*      parameters;
} InitArgs;
// base class for embedded controllers
class EmbeddedController : public controller::BaseController
{
public:

    EmbeddedController(InitArgs* args = nullptr);
    virtual ~EmbeddedController() = default;


    virtual void LinkObject(Object* object);
    virtual void UnlinkObject();
    virtual void SetScenarioEngine(ScenarioEngine* scenario_engine);
    virtual void SetPlayer(ScenarioPlayer* player);
    Object*     GetRoadObject();
    Object* GetLinkedObject();
    // Base class Step function should be called from derived classes
    virtual void Step(double timeStep) override;
    //Riz - moved the functionality to base class        
    /*
    enum Type
    {
        CONTROLLER_TYPE_DEFAULT,
        CONTROLLER_TYPE_EXTERNAL,
        CONTROLLER_TYPE_FOLLOW_GHOST,
        CONTROLLER_TYPE_FOLLOW_ROUTE,
        CONTROLLER_TYPE_INTERACTIVE,
        CONTROLLER_TYPE_SLOPPY_DRIVER,
        CONTROLLER_TYPE_SUMO,
        CONTROLLER_TYPE_REL2ABS,
        CONTROLLER_TYPE_ACC,
        CONTROLLER_TYPE_ALKS,
        CONTROLLER_TYPE_UDP_DRIVER,
        CONTROLLER_TYPE_ECE_ALKS_REF_DRIVER,
        CONTROLLER_ALKS_R157SM,
        CONTROLLER_TYPE_LOOMING,
        CONTROLLER_TYPE_OFFROAD_FOLLOWER,
        N_CONTROLLER_TYPES,
        CONTROLLER_TYPE_UNDEFINED,
        GHOST_RESERVED_TYPE       = 100,
        USER_CONTROLLER_TYPE_BASE = 1000,
    };
    static const char* GetTypeNameStatic()
    {
        return CONTROLLER_BASE_TYPE_NAME;
    }
    virtual const char* GetTypeName()
    {
        return GetTypeNameStatic();
    }
    static int GetTypeStatic()
    {
        return CONTROLLER_BASE_TYPE_ID;
    }        
    virtual int GetType()
    {
        return GetTypeStatic();
    }
    
    virtual int  Activate(ControlActivationMode lat_mode,
                            ControlActivationMode long_mode,
                            ControlActivationMode light_mode,
                            ControlActivationMode anim_mode);
    
    virtual void Deactivate()
    {
        active_domains_ = static_cast<unsigned int>(ControlDomains::DOMAIN_NONE);
    };

    virtual void DeactivateDomains(unsigned int domains)
    {
        active_domains_ = active_domains_ & ~domains;
    };

    // Executed by scenarioengine before first step
    virtual void Init(){};

    // Executed by player after player and viewer intialization
    virtual void InitPostPlayer(){};

    virtual void ReportKeyEvent(int key, bool down);

    bool Active()
    {
        return (active_domains_ != static_cast<unsigned int>(ControlDomains::DOMAIN_NONE));
    };

    std::string GetName()
    {
        return name_;
    }

    void SetName(std::string name)
    {
        name_ = name;
    }

    unsigned int GetOperatingDomains()
    {
        return operating_domains_;
    }

    unsigned int GetActiveDomains()
    {
        return active_domains_;
    }

    ControlOperationMode GetMode()
    {
        return mode_;
    }
    
    std::string Mode2Str(ControlOperationMode mode);
    
    bool    IsActiveOnDomainsOnly(unsigned int domainMask);
    bool    IsActiveOnDomains(unsigned int domainMask);
    bool    IsNotActiveOnDomains(unsigned int domainMask);
    bool    IsActiveOnAnyOfDomains(unsigned int domainMask);
    bool    IsActive();
    */        

protected:
    
    Object*              object_;             // The object to which the controller is attached and hence controls
    Entities*            entities_;
    ScenarioGateway*     gateway_;
    ScenarioEngine*      scenario_engine_;
    ScenarioPlayer*      player_;

    //Riz - moved the functionality to the base class
    /* 
    unsigned int         operating_domains_;  // bitmask representing domains controller is operating on
    unsigned int         active_domains_;     // bitmask representing domains controller is currently active on
    ControlOperationMode mode_;               // add to scenario actions or replace        
    std::string          name_;
    std::string          type_name_;
    */
};

typedef EmbeddedController* (*ControllerInstantiateFunction)(void* args);
EmbeddedController* InstantiateController(void* args);

}   // namespace controller
    
}  // namespace scenarioengine