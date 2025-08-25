#ifndef STATE_REGULATOR_STATE_REGULATOR_CONFIG_H
#define STATE_REGULATOR_STATE_REGULATOR_CONFIG_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef float float32_t;

#define STATE_REGULATOR_MATRIX_INDEX(MATRIX, ROW, COLUMN) \
    ((MATRIX)->data[(ROW) + (MATRIX)->rows * (COLUMN)])

typedef struct {
    size_t rows;
    size_t columns;
    float32_t* data;
} state_regulator_matrix_t;

typedef enum {
    STATE_REGULATOR_ERR_OK = 0,
    STATE_REGULATOR_ERR_FAIL,
    STATE_REGULATOR_ERR_NULL,
	STATE_REGULATOR_ERR_DIMENSION,
} state_regulator_err_t;

typedef struct {
    state_regulator_matrix_t state;
} state_regulator_state_t;

typedef struct {
    state_regulator_matrix_t state_matrix;
    state_regulator_matrix_t measurement_matrix;
} state_regulator_config_t;

#ifdef __cplusplus
}
#endif

#endif // STATE_REGULATOR_STATE_REGULATOR_CONFIG_H
