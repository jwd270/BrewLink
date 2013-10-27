// MESSAGE TEMPERATURE_READING PACKING

#define MAVLINK_MSG_ID_TEMPERATURE_READING 1

typedef struct __mavlink_temperature_reading_t
{
 int16_t temp; ///< Temperature data
 uint8_t tempType; ///< Temperature type data.  Bit masks described by BREWLINK_TEMP_MASK enum, and the data fields are described by their respective enum. 
} mavlink_temperature_reading_t;

#define MAVLINK_MSG_ID_TEMPERATURE_READING_LEN 3
#define MAVLINK_MSG_ID_1_LEN 3

#define MAVLINK_MSG_ID_TEMPERATURE_READING_CRC 234
#define MAVLINK_MSG_ID_1_CRC 234



#define MAVLINK_MESSAGE_INFO_TEMPERATURE_READING { \
	"TEMPERATURE_READING", \
	2, \
	{  { "temp", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_temperature_reading_t, temp) }, \
         { "tempType", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_temperature_reading_t, tempType) }, \
         } \
}


/**
 * @brief Pack a temperature_reading message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param temp Temperature data
 * @param tempType Temperature type data.  Bit masks described by BREWLINK_TEMP_MASK enum, and the data fields are described by their respective enum. 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_temperature_reading_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t temp, uint8_t tempType)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEMPERATURE_READING_LEN];
	_mav_put_int16_t(buf, 0, temp);
	_mav_put_uint8_t(buf, 2, tempType);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN);
#else
	mavlink_temperature_reading_t packet;
	packet.temp = temp;
	packet.tempType = tempType;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEMPERATURE_READING;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN, MAVLINK_MSG_ID_TEMPERATURE_READING_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN);
#endif
}

/**
 * @brief Pack a temperature_reading message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param temp Temperature data
 * @param tempType Temperature type data.  Bit masks described by BREWLINK_TEMP_MASK enum, and the data fields are described by their respective enum. 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_temperature_reading_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t temp,uint8_t tempType)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEMPERATURE_READING_LEN];
	_mav_put_int16_t(buf, 0, temp);
	_mav_put_uint8_t(buf, 2, tempType);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN);
#else
	mavlink_temperature_reading_t packet;
	packet.temp = temp;
	packet.tempType = tempType;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEMPERATURE_READING;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN, MAVLINK_MSG_ID_TEMPERATURE_READING_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN);
#endif
}

/**
 * @brief Encode a temperature_reading struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param temperature_reading C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_temperature_reading_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_temperature_reading_t* temperature_reading)
{
	return mavlink_msg_temperature_reading_pack(system_id, component_id, msg, temperature_reading->temp, temperature_reading->tempType);
}

/**
 * @brief Encode a temperature_reading struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param temperature_reading C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_temperature_reading_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_temperature_reading_t* temperature_reading)
{
	return mavlink_msg_temperature_reading_pack_chan(system_id, component_id, chan, msg, temperature_reading->temp, temperature_reading->tempType);
}

/**
 * @brief Send a temperature_reading message
 * @param chan MAVLink channel to send the message
 *
 * @param temp Temperature data
 * @param tempType Temperature type data.  Bit masks described by BREWLINK_TEMP_MASK enum, and the data fields are described by their respective enum. 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_temperature_reading_send(mavlink_channel_t chan, int16_t temp, uint8_t tempType)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TEMPERATURE_READING_LEN];
	_mav_put_int16_t(buf, 0, temp);
	_mav_put_uint8_t(buf, 2, tempType);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEMPERATURE_READING, buf, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN, MAVLINK_MSG_ID_TEMPERATURE_READING_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEMPERATURE_READING, buf, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN);
#endif
#else
	mavlink_temperature_reading_t packet;
	packet.temp = temp;
	packet.tempType = tempType;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEMPERATURE_READING, (const char *)&packet, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN, MAVLINK_MSG_ID_TEMPERATURE_READING_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEMPERATURE_READING, (const char *)&packet, MAVLINK_MSG_ID_TEMPERATURE_READING_LEN);
#endif
#endif
}

#endif

// MESSAGE TEMPERATURE_READING UNPACKING


/**
 * @brief Get field temp from temperature_reading message
 *
 * @return Temperature data
 */
static inline int16_t mavlink_msg_temperature_reading_get_temp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field tempType from temperature_reading message
 *
 * @return Temperature type data.  Bit masks described by BREWLINK_TEMP_MASK enum, and the data fields are described by their respective enum. 
 */
static inline uint8_t mavlink_msg_temperature_reading_get_tempType(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a temperature_reading message into a struct
 *
 * @param msg The message to decode
 * @param temperature_reading C-struct to decode the message contents into
 */
static inline void mavlink_msg_temperature_reading_decode(const mavlink_message_t* msg, mavlink_temperature_reading_t* temperature_reading)
{
#if MAVLINK_NEED_BYTE_SWAP
	temperature_reading->temp = mavlink_msg_temperature_reading_get_temp(msg);
	temperature_reading->tempType = mavlink_msg_temperature_reading_get_tempType(msg);
#else
	memcpy(temperature_reading, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_TEMPERATURE_READING_LEN);
#endif
}
