#include "state_regulator.h"
#include <string.h>

state_regulator_err_t state_regulator_initialize(
    state_regulator_t* regulator,
    state_regulator_config_t const* config)
{
    if (regulator == NULL || config == NULL) {
        return STATE_REGULATOR_ERR_NULL;
    }

    memset(regulator, 0, sizeof(*regulator));
    memcpy(&regulator->config, config, sizeof(*config));

    return STATE_REGULATOR_ERR_OK;
}

state_regulator_err_t state_regulator_deinitialize(state_regulator_t* regulator)
{
    if (regulator == NULL) {
        return STATE_REGULATOR_ERR_NULL;
    }

    memset(regulator, 0, sizeof(*regulator));

    return STATE_REGULATOR_ERR_OK;
}

state_regulator_err_t state_regulator_get_control(
    state_regulator_t* regulator, 
	state_regulator_matrix_t const* reference,
    state_regulator_matrix_t const* measure,
    state_regulator_matrix_t* control)
{
    if (regulator == NULL || input == NULL || output == NULL ||
        control == NULL) {
        return STATE_REGULATOR_ERR_NULL;
    }

	if (reference->columns != 1U || measure->columns != 1U || reference->rows != measure->rows) {
		return STATE_REGULATOR_ERR_DIMENSION;
	}

	uint8_t system_dimension = reference->rows;
	
	if (control->rows != 1U || control->rows != reference->rows) {
		return STATE_REGULATOR_ERR_DIMENSION;
	}

	if (regulator->config.state_transition.rows != regulator->config.state_transition.columns) {
		return STATE_REGULATOR_ERR_DIMENSION;
	}
	
	// x_next = A*x + B*u
	// y = C*x + D*u
	
    return STATE_REGULATOR_ERR_OK;
}
