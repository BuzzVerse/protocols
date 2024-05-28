#include <stdint.h>

#define DATA_SIZE 59
#define META_DATA_SIZE 5
#define PACKET_SIZE (DATA_SIZE + META_DATA_SIZE)

/**
 * @brief Structure representing a LoRa packet.
 *
 * @details This structure holds the data for a LoRa packet, including an ID,
 * version, message ID, message count, data type, and the actual data payload.
 */
typedef struct
{
    uint8_t version;         /**< 4 bits version + 4 bits reserved for later use */
    uint8_t id;              /**< 4 bits class + 4 bits device ID */
    uint8_t msgID;           /**< 1 byte message ID */
    uint8_t msgCount;        /**< 1 byte message count (optional, can be zero if not used) */
    uint8_t dataType;        /**< 1 byte data type */
    uint8_t data[DATA_SIZE]; /**< Data payload */
} packet_t;