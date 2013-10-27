// MESSAGE BATTERY_VOLTAGE PACKING

#define MAVLINK_MSG_ID_BATTERY_VOLTAGE 2

typedef struct __mavlink_battery_voltage_t
{
 int16_t battVolts; ///<  The voltage of the attached battery 
 uint8_t scale; ///<  The scale of the voltage measurement as described by the BREWLINK_VALUE_SCALE enum
} mavlink_battery_voltage_t;

#define MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN 3
#define MAVLINK_MSG_ID_2_LEN 3

#define MAVLINK_MSG_ID_BATTERY_VOLTAGE_CRC 230
#define MAVLINK_MSG_ID_2_CRC 230



#define MAVLINK_MESSAGE_INFO_BATTERY_VOLTAGE { \
	"BATTERY_VOLTAGE", \
	2, \
	{  { "battVolts", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_battery_voltage_t, battVolts) }, \
         { "scale", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_battery_voltage_t, scale) }, \
         } \
}


/**
 * @brief Pack a battery_voltage message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param battVolts  The voltage of the attached battery 
 * @param scale  The scale of the voltage measurement as described by the BREWLINK_VALUE_SCALE enum
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_battery_voltage_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t battVolts, uint8_t scale)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN];
	_mav_put_int16_t(buf, 0, battVolts);
	_mav_put_uint8_t(buf, 2, scale);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN);
#else
	mavlink_battery_voltage_t packet;
	packet.battVolts = battVolts;
	packet.scale = scale;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BATTERY_VOLTAGE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN, MAVLINK_MSG_ID_BATTERY_VOLTAGE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN);
#endif
}

/**
 * @brief Pack a battery_voltage message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param battVolts  The voltage of the attached battery 
 * @param scale  The scale of the voltage measurement as described by the BREWLINK_VALUE_SCALE enum
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_battery_voltage_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t battVolts,uint8_t scale)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN];
	_mav_put_int16_t(buf, 0, battVolts);
	_mav_put_uint8_t(buf, 2, scale);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN);
#else
	mavlink_battery_voltage_t packet;
	packet.battVolts = battVolts;
	packet.scale = scale;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_BATTERY_VOLTAGE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN, MAVLINK_MSG_ID_BATTERY_VOLTAGE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN);
#endif
}

/**
 * @brief Encode a battery_voltage struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param battery_voltage C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_battery_voltage_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_battery_voltage_t* battery_voltage)
{
	return mavlink_msg_battery_voltage_pack(system_id, component_id, msg, battery_voltage->battVolts, battery_voltage->scale);
}

/**
 * @brief Encode a battery_voltage struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param battery_voltage C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_battery_voltage_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_battery_voltage_t* battery_voltage)
{
	return mavlink_msg_battery_voltage_pack_chan(system_id, component_id, chan, msg, battery_voltage->battVolts, battery_voltage->scale);
}

/**
 * @brief Send a battery_voltage message
 * @param chan MAVLink channel to send the message
 *
 * @param battVolts  The voltage of the attached battery 
 * @param scale  The scale of the voltage measurement as described by the BREWLINK_VALUE_SCALE enum
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_battery_voltage_send(mavlink_channel_t chan, int16_t battVolts, uint8_t scale)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN];
	_mav_put_int16_t(buf, 0, battVolts);
	_mav_put_uint8_t(buf, 2, scale);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BATTERY_VOLTAGE, buf, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN, MAVLINK_MSG_ID_BATTERY_VOLTAGE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BATTERY_VOLTAGE, buf, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN);
#endif
#else
	mavlink_battery_voltage_t packet;
	packet.battVolts = battVolts;
	packet.scale = scale;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BATTERY_VOLTAGE, (const char *)&packet, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN, MAVLINK_MSG_ID_BATTERY_VOLTAGE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BATTERY_VOLTAGE, (const char *)&packet, MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN);
#endif
#endif
}

#endif

// MESSAGE BATTERY_VOLTAGE UNPACKING


/**
 * @brief Get field battVolts from battery_voltage message
 *
 * @return  The voltage of the attached battery 
 */
static inline int16_t mavlink_msg_battery_voltage_get_battVolts(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field scale from battery_voltage message
 *
 * @return  The scale of the voltage measurement as described by the BREWLINK_VALUE_SCALE enum
 */
static inline uint8_t mavlink_msg_battery_voltage_get_scale(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a battery_voltage message into a struct
 *
 * @param msg The message to decode
 * @param battery_voltage C-struct to decode the message contents into
 */
static inline void mavlink_msg_battery_voltage_decode(const mavlink_message_t* msg, mavlink_battery_voltage_t* battery_voltage)
{
#if MAVLINK_NEED_BYTE_SWAP
	battery_voltage->battVolts = mavlink_msg_battery_voltage_get_battVolts(msg);
	battery_voltage->scale = mavlink_msg_battery_voltage_get_scale(msg);
#else
	memcpy(battery_voltage, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_BATTERY_VOLTAGE_LEN);
#endif
}
