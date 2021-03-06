/**
   \file
*/

#ifndef CNOID_EDITMODEL_PLUGIN_SENSOR_ITEM_H
#define CNOID_EDITMODEL_PLUGIN_SENSOR_ITEM_H

#include <cnoid/Item>
#include <cnoid/Body>
#include <cnoid/Link>
#include <cnoid/SceneProvider>
#include <cnoid/VRML>
#include <cnoid/VRMLBodyLoader>
#include <boost/optional.hpp>
#include "EditableModelBase.h"
#include "exportdecl.h"

namespace cnoid {

class SensorItem;
typedef ref_ptr<SensorItem> SensorItemPtr;
class SensorItemImpl;

class CNOID_EXPORT SensorItem : public SceneProvider, public EditableModelBase
{
public:
    static void initializeClass(ExtensionManager* ext);
        
    SensorItem();
    SensorItem(const SensorItem& org);
    SensorItem(Device* dev);
    virtual ~SensorItem();

    VRMLNodePtr toVRML();
    std::string toURDF();
    
    Device* device() const;
    
    virtual SgNode* getScene();

protected:
    virtual Item* doDuplicate() const;
    virtual void doAssign(Item* item);
    virtual void doPutProperties(PutPropertyFunction& putProperty);
    virtual bool store(Archive& archive);
    virtual bool restore(const Archive& archive);
            
private:
    friend class SensorItemImpl;
    SensorItemImpl* impl;
};
}

#endif
