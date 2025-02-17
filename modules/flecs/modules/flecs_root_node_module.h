#ifndef FLECS_ROOT_NODE_MODULE_H
#define FLECS_ROOT_NODE_MODULE_H


#include "../components/flecs_root_node_component.h"
#include "../flecs_sync_mod.h"
#include "../flecs_world.h"
#include "core/object/class_db.h"
#include "core/object/object.h"


namespace modules {

struct FlecsRootNodeModule {
	FlecsRootNodeModule(flecs::world &world) {

		world.module<FlecsRootNodeModule>();
		world.component<components::FlecsRootNode>();
		_register_systems(world);
	}

	void _register_systems(flecs::world &world);
};

} //namespace modules

class FlecsRootNodeMod : public FlecsSyncMod {
	GDCLASS(FlecsRootNodeMod, FlecsSyncMod);

protected:
	static void _bind_methods();

public:
	virtual void initialize(flecs::entity &prefab, flecs::world &world) override;
	virtual void initialize_entity_data(FlecsEntityNode *entity, flecs::world &world) override;

};

#endif