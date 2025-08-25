#ifndef STATE_REGULATOR_STATE_REGULATOR_H
#define STATE_REGULATOR_STATE_REGULATOR_H

#include "state_regulator_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    state_regulator_state_t state;
    state_regulator_config_t config;
} state_regulator_t;

state_regulator_err_t state_regulator_initialize(
    state_regulator_t* regulator,
    state_regulator_config_t const* config);
state_regulator_err_t state_regulator_deinitialize(
    state_regulator_t* regulator);

state_regulator_err_t state_regulator_get_control(
    state_regulator_t* regulator,
    state_regulator_matrix_t const* input,
    state_regulator_matrix_t const* output,
    state_regulator_matrix_t* control);

#ifdef __cplusplus
}
#endif

#endif // STATE_REGULATOR_STATE_REGULATOR_H
