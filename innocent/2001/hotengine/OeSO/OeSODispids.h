
#pragma once

#define DISPID_IOeSOParser_onLoaded		1

#define DISPID_IOeSOAttribute_onChanged		1


#define ID_IOeSO_name				1000
#define ID_IOeSO_value				1001
#define ID_IOeSO_attribute			2000
#define ID_IOeSO_attribute2			2001
#define ID_IOeSO_method				2010
#define ID_IOeSO_event				2020
#define ID_IOeSO_inherits			3000
#define ID_IOeSO_derives			3001
#define ID_IOeSO_interface			3002
#define ID_IOeSO_count				4000
#define ID_IOeSO_member				4001

#define ID_IOeSOObject_name			ID_IOeSO_name
#define ID_IOeSOObject_attributes		0
#define ID_IOeSOObject_attributesObject		ID_IOeSO_attribute
#define ID_IOeSOObject_methods_			ID_IOeSO_method
#define ID_IOeSOObject_events_			ID_IOeSO_event
#define ID_IOeSOObject_ofclass			ID_IOeSO_inherits

#define ID_IOeSOInterface_name			0
#define ID_IOeSOInterface_methods_		ID_IOeSO_method
#define ID_IOeSOInterface_events_		ID_IOeSO_event
#define ID_IOeSOInterface_inherits		ID_IOeSO_inherits
#define ID_IOeSOInterface_derives		ID_IOeSO_derives
#define ID_IOeSOInterface_interfaces		ID_IOeSO_interface

#define ID_IOeSOClass_instances			0
#define ID_IOeSOClass_name			ID_IOeSO_name
#define ID_IOeSOClass_attributes		ID_IOeSO_attribute
#define ID_IOeSOClass_attributesObject		ID_IOeSO_attribute2
#define ID_IOeSOClass_methods_			ID_IOeSO_method
#define ID_IOeSOClass_events_			ID_IOeSO_event
#define ID_IOeSOClass_inherits			ID_IOeSO_inherits
#define ID_IOeSOClass_derives			ID_IOeSO_derives
#define ID_IOeSOClass_interfaces		ID_IOeSO_interface

#define ID_IOeSOAttribute_name			ID_IOeSO_name
#define ID_IOeSOAttribute_value			0

#define ID_IOeSOStatus_name			ID_IOeSO_name

#define ID_IOeSOMethod_name			ID_IOeSO_name

#define ID_IOeSOEvent_name			ID_IOeSO_name
