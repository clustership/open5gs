
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_area_info_1.h"

OpenAPI_network_area_info_1_t *OpenAPI_network_area_info_1_create(
    OpenAPI_list_t *ecgis,
    OpenAPI_list_t *ncgis,
    OpenAPI_list_t *g_ran_node_ids,
    OpenAPI_list_t *tais
)
{
    OpenAPI_network_area_info_1_t *network_area_info_1_local_var = OpenAPI_malloc(sizeof(OpenAPI_network_area_info_1_t));
    if (!network_area_info_1_local_var) {
        return NULL;
    }
    network_area_info_1_local_var->ecgis = ecgis;
    network_area_info_1_local_var->ncgis = ncgis;
    network_area_info_1_local_var->g_ran_node_ids = g_ran_node_ids;
    network_area_info_1_local_var->tais = tais;

    return network_area_info_1_local_var;
}

void OpenAPI_network_area_info_1_free(OpenAPI_network_area_info_1_t *network_area_info_1)
{
    if (NULL == network_area_info_1) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_list_for_each(network_area_info_1->ecgis, node) {
        OpenAPI_ecgi_1_free(node->data);
    }
    OpenAPI_list_free(network_area_info_1->ecgis);
    OpenAPI_list_for_each(network_area_info_1->ncgis, node) {
        OpenAPI_ncgi_1_free(node->data);
    }
    OpenAPI_list_free(network_area_info_1->ncgis);
    OpenAPI_list_for_each(network_area_info_1->g_ran_node_ids, node) {
        OpenAPI_global_ran_node_id_1_free(node->data);
    }
    OpenAPI_list_free(network_area_info_1->g_ran_node_ids);
    OpenAPI_list_for_each(network_area_info_1->tais, node) {
        OpenAPI_tai_1_free(node->data);
    }
    OpenAPI_list_free(network_area_info_1->tais);
    ogs_free(network_area_info_1);
}

cJSON *OpenAPI_network_area_info_1_convertToJSON(OpenAPI_network_area_info_1_t *network_area_info_1)
{
    cJSON *item = NULL;

    if (network_area_info_1 == NULL) {
        ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed [NetworkAreaInfo_1]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (network_area_info_1->ecgis) {
    cJSON *ecgisList = cJSON_AddArrayToObject(item, "ecgis");
    if (ecgisList == NULL) {
        ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed [ecgis]");
        goto end;
    }

    OpenAPI_lnode_t *ecgis_node;
    if (network_area_info_1->ecgis) {
        OpenAPI_list_for_each(network_area_info_1->ecgis, ecgis_node) {
            cJSON *itemLocal = OpenAPI_ecgi_1_convertToJSON(ecgis_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed [ecgis]");
                goto end;
            }
            cJSON_AddItemToArray(ecgisList, itemLocal);
        }
    }
    }

    if (network_area_info_1->ncgis) {
    cJSON *ncgisList = cJSON_AddArrayToObject(item, "ncgis");
    if (ncgisList == NULL) {
        ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed [ncgis]");
        goto end;
    }

    OpenAPI_lnode_t *ncgis_node;
    if (network_area_info_1->ncgis) {
        OpenAPI_list_for_each(network_area_info_1->ncgis, ncgis_node) {
            cJSON *itemLocal = OpenAPI_ncgi_1_convertToJSON(ncgis_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed [ncgis]");
                goto end;
            }
            cJSON_AddItemToArray(ncgisList, itemLocal);
        }
    }
    }

    if (network_area_info_1->g_ran_node_ids) {
    cJSON *g_ran_node_idsList = cJSON_AddArrayToObject(item, "gRanNodeIds");
    if (g_ran_node_idsList == NULL) {
        ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed [g_ran_node_ids]");
        goto end;
    }

    OpenAPI_lnode_t *g_ran_node_ids_node;
    if (network_area_info_1->g_ran_node_ids) {
        OpenAPI_list_for_each(network_area_info_1->g_ran_node_ids, g_ran_node_ids_node) {
            cJSON *itemLocal = OpenAPI_global_ran_node_id_1_convertToJSON(g_ran_node_ids_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed [g_ran_node_ids]");
                goto end;
            }
            cJSON_AddItemToArray(g_ran_node_idsList, itemLocal);
        }
    }
    }

    if (network_area_info_1->tais) {
    cJSON *taisList = cJSON_AddArrayToObject(item, "tais");
    if (taisList == NULL) {
        ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed [tais]");
        goto end;
    }

    OpenAPI_lnode_t *tais_node;
    if (network_area_info_1->tais) {
        OpenAPI_list_for_each(network_area_info_1->tais, tais_node) {
            cJSON *itemLocal = OpenAPI_tai_1_convertToJSON(tais_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed [tais]");
                goto end;
            }
            cJSON_AddItemToArray(taisList, itemLocal);
        }
    }
    }

end:
    return item;
}

OpenAPI_network_area_info_1_t *OpenAPI_network_area_info_1_parseFromJSON(cJSON *network_area_info_1JSON)
{
    OpenAPI_network_area_info_1_t *network_area_info_1_local_var = NULL;
    cJSON *ecgis = cJSON_GetObjectItemCaseSensitive(network_area_info_1JSON, "ecgis");

    OpenAPI_list_t *ecgisList;
    if (ecgis) {
    cJSON *ecgis_local_nonprimitive;
    if (!cJSON_IsArray(ecgis)){
        ogs_error("OpenAPI_network_area_info_1_parseFromJSON() failed [ecgis]");
        goto end;
    }

    ecgisList = OpenAPI_list_create();

    cJSON_ArrayForEach(ecgis_local_nonprimitive, ecgis ) {
        if (!cJSON_IsObject(ecgis_local_nonprimitive)) {
            ogs_error("OpenAPI_network_area_info_1_parseFromJSON() failed [ecgis]");
            goto end;
        }
        OpenAPI_ecgi_1_t *ecgisItem = OpenAPI_ecgi_1_parseFromJSON(ecgis_local_nonprimitive);

        OpenAPI_list_add(ecgisList, ecgisItem);
    }
    }

    cJSON *ncgis = cJSON_GetObjectItemCaseSensitive(network_area_info_1JSON, "ncgis");

    OpenAPI_list_t *ncgisList;
    if (ncgis) {
    cJSON *ncgis_local_nonprimitive;
    if (!cJSON_IsArray(ncgis)){
        ogs_error("OpenAPI_network_area_info_1_parseFromJSON() failed [ncgis]");
        goto end;
    }

    ncgisList = OpenAPI_list_create();

    cJSON_ArrayForEach(ncgis_local_nonprimitive, ncgis ) {
        if (!cJSON_IsObject(ncgis_local_nonprimitive)) {
            ogs_error("OpenAPI_network_area_info_1_parseFromJSON() failed [ncgis]");
            goto end;
        }
        OpenAPI_ncgi_1_t *ncgisItem = OpenAPI_ncgi_1_parseFromJSON(ncgis_local_nonprimitive);

        OpenAPI_list_add(ncgisList, ncgisItem);
    }
    }

    cJSON *g_ran_node_ids = cJSON_GetObjectItemCaseSensitive(network_area_info_1JSON, "gRanNodeIds");

    OpenAPI_list_t *g_ran_node_idsList;
    if (g_ran_node_ids) {
    cJSON *g_ran_node_ids_local_nonprimitive;
    if (!cJSON_IsArray(g_ran_node_ids)){
        ogs_error("OpenAPI_network_area_info_1_parseFromJSON() failed [g_ran_node_ids]");
        goto end;
    }

    g_ran_node_idsList = OpenAPI_list_create();

    cJSON_ArrayForEach(g_ran_node_ids_local_nonprimitive, g_ran_node_ids ) {
        if (!cJSON_IsObject(g_ran_node_ids_local_nonprimitive)) {
            ogs_error("OpenAPI_network_area_info_1_parseFromJSON() failed [g_ran_node_ids]");
            goto end;
        }
        OpenAPI_global_ran_node_id_1_t *g_ran_node_idsItem = OpenAPI_global_ran_node_id_1_parseFromJSON(g_ran_node_ids_local_nonprimitive);

        OpenAPI_list_add(g_ran_node_idsList, g_ran_node_idsItem);
    }
    }

    cJSON *tais = cJSON_GetObjectItemCaseSensitive(network_area_info_1JSON, "tais");

    OpenAPI_list_t *taisList;
    if (tais) {
    cJSON *tais_local_nonprimitive;
    if (!cJSON_IsArray(tais)){
        ogs_error("OpenAPI_network_area_info_1_parseFromJSON() failed [tais]");
        goto end;
    }

    taisList = OpenAPI_list_create();

    cJSON_ArrayForEach(tais_local_nonprimitive, tais ) {
        if (!cJSON_IsObject(tais_local_nonprimitive)) {
            ogs_error("OpenAPI_network_area_info_1_parseFromJSON() failed [tais]");
            goto end;
        }
        OpenAPI_tai_1_t *taisItem = OpenAPI_tai_1_parseFromJSON(tais_local_nonprimitive);

        OpenAPI_list_add(taisList, taisItem);
    }
    }

    network_area_info_1_local_var = OpenAPI_network_area_info_1_create (
        ecgis ? ecgisList : NULL,
        ncgis ? ncgisList : NULL,
        g_ran_node_ids ? g_ran_node_idsList : NULL,
        tais ? taisList : NULL
    );

    return network_area_info_1_local_var;
end:
    return NULL;
}

OpenAPI_network_area_info_1_t *OpenAPI_network_area_info_1_copy(OpenAPI_network_area_info_1_t *dst, OpenAPI_network_area_info_1_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_network_area_info_1_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_network_area_info_1_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_network_area_info_1_free(dst);
    dst = OpenAPI_network_area_info_1_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

