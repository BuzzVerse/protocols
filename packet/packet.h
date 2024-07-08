#ifndef PACKET_H
#define PACKET_H

#include <stdint.h>

#define DATA_SIZE 59
#define META_DATA_SIZE 5
#define PACKET_SIZE (DATA_SIZE + META_DATA_SIZE)

#define PACKET_VERSION_IDX 0
#define PACKET_ID_IDX 1
#define PACKET_MSG_ID_IDX 2
#define PACKET_MSG_COUNT_IDX 3
#define PACKET_DATA_TYPE_IDX 4

typedef enum
{
    BME280 = 1,
    BMA400 = 2,
    MQ2 = 3,
    GPS = 4,
    SMS = 32
} DataType;

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
    DataType dataType;  /**< 1 byte data type */
    uint8_t data[DATA_SIZE]; /**< Data payload */
} packet_t;

#endif // PACKET_H