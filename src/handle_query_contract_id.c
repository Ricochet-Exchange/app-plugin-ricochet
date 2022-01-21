#include "ricochet_plugin.h"

void handle_query_contract_id(void *parameters) {
    ethQueryContractID_t *msg = (ethQueryContractID_t *) parameters;
    const context_t *context = (context_t *) msg->pluginContext;

    strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);
    switch (context->selectorIndex) {
        case DOWNGRADE:
        case DOWNGRADE_TO_ETH:
            strlcpy(msg->version, "Downgrade", msg->versionLength);
            break;
        case DISTRIBUTE:
            strlcpy(msg->version, "Distribute", msg->versionLength);
            break;
        case UPGRADE:
        case UPGRADE_TO_ETH:
            strlcpy(msg->version, "Upgrade", msg->versionLength);
            break;
        default:
            PRINTF("Selector index: %d not supported\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }
    msg->result = ETH_PLUGIN_RESULT_OK;
}