// MESSAGE HEARBEAT PACKING

#define MAVLINK_MSG_ID_HEARBEAT 0

typedef struct __mavlink_hearbeat_t
{
 uint8_t device; ///< Device ID, defined in the BREWLINK_DEVICES enum
 uint8_t type; ///< Device type, defined in the BREWLINK_DEVICE_TYPE enum
 uint8_t mode; ///< Device mode flags, defined in the BREWLINK_STATUS enum 
 uint8_t brewlink_version; ///< Brewlink version, not writeable by the user.
} mavlink_hearbeat_t;

#define MAVLINK_MSG_ID_HEARBEAT_LEN 4
#define MAVLINK_MSG_ID_0_LEN 4

#define MAVLINK_MSG_ID_HEARBEAT_CRC 253
#define MAVLINK_MSG_ID_0_CRC 253



#define MAVLINK_MESSAGE_INFO_HEARBEAT { \
	"HEARBEAT", \
	4, \
	{  { "device", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_hearbeat_t, device) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_hearbeat_t, type) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_hearbeat_t, mode) }, \
         { "brewlink_version", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_hearbeat_t, brewlink_version) }, \
         } \
}


/**
 * @brief Pack a hearbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param device Device ID, defined in the BREWLINK_DEVICES enum
 * @param type Device type, defined in the BREWLINK_DEVICE_TYPE enum
 * @param mode Device mode flags, defined in the BREWLINK_STATUS enum 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hearbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t device, uint8_t type, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HEARBEAT_LEN];
	_mav_put_uint8_t(buf, 0, device);
	_mav_put_uint8_t(buf, 1, type);
	_mav_put_uint8_t(buf, 2, mode);
	_mav_put_uint8_t(buf, 3, 3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARBEAT_LEN);
#else
	mavlink_hearbeat_t packet;
	packet.device = device;
	packet.type = type;
	packet.mode = mode;
	packet.brewlink_version = 3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARBEAT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HEARBEAT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEARBEAT_LEN, MAVLINK_MSG_ID_HEARBEAT_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEARBEAT_LEN);
#endif
}

/**
 * @brief Pack a hearbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param device Device ID, defined in the BREWLINK_DEVICES enum
 * @param type Device type, defined in the BREWLINK_DEVICE_TYPE enum
 * @param mode Device mode flags, defined in the BREWLINK_STATUS enum 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hearbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t device,uint8_t type,uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HEARBEAT_LEN];
	_mav_put_uint8_t(buf, 0, device);
	_mav_put_uint8_t(buf, 1, type);
	_mav_put_uint8_t(buf, 2, mode);
	_mav_put_uint8_t(buf, 3, 3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARBEAT_LEN);
#else
	mavlink_hearbeat_t packet;
	packet.device = device;
	packet.type = type;
	packet.mode = mode;
	packet.brewlink_version = 3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARBEAT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HEARBEAT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEARBEAT_LEN, MAVLINK_MSG_ID_HEARBEAT_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEARBEAT_LEN);
#endif
}

/**
 * @brief Encode a hearbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hearbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hearbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hearbeat_t* hearbeat)
{
	return mavlink_msg_hearbeat_pack(system_id, component_id, msg, hearbeat->device, hearbeat->type, hearbeat->mode);
}

/**
 * @brief Encode a hearbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hearbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hearbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hearbeat_t* hearbeat)
{
	return mavlink_msg_hearbeat_pack_chan(system_id, component_id, chan, msg, hearbeat->device, hearbeat->type, hearbeat->mode);
}

/**
 * @brief Send a hearbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param device Device ID, defined in the BREWLINK_DEVICES enum
 * @param type Device type, defined in the BREWLINK_DEVICE_TYPE enum
 * @param mode Device mode flags, defined in the BREWLINK_STATUS enum 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hearbeat_send(mavlink_channel_t chan, uint8_t device, uint8_t type, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HEARBEAT_LEN];
	_mav_put_uint8_t(buf, 0, device);
	_mav_put_uint8_t(buf, 1, type);
	_mav_put_uint8_t(buf, 2, mode);
	_mav_put_uint8_t(buf, 3, 3);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARBEAT, buf, MAVLINK_MSG_ID_HEARBEAT_LEN, MAVLINK_MSG_ID_HEARBEAT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARBEAT, buf, MAVLINK_MSG_ID_HEARBEAT_LEN);
#endif
#else
	mavlink_hearbeat_t packet;
	packet.device = device;
	packet.type = type;
	packet.mode = mode;
	packet.brewlink_version = 3;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARBEAT, (const char *)&packet, MAVLINK_MSG_ID_HEARBEAT_LEN, MAVLINK_MSG_ID_HEARBEAT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARBEAT, (const char *)&packet, MAVLINK_MSG_ID_HEARBEAT_LEN);
#endif
#endif
}

#endif

// MESSAGE HEARBEAT UNPACKING


/**
 * @brief Get field device from hearbeat message
 *
 * @return Device ID, defined in the BREWLINK_DEVICES enum
 */
static inline uint8_t mavlink_msg_hearbeat_get_device(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field type from hearbeat message
 *
 * @return Device type, defined in the BREWLINK_DEVICE_TYPE enum
 */
static inline uint8_t mavlink_msg_hearbeat_get_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field mode from hearbeat message
 *
 * @return Device mode flags, defined in the BREWLINK_STATUS enum 
 */
static inline uint8_t mavlink_msg_hearbeat_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field brewlink_version from hearbeat message
 *
 * @return Brewlink version, not writeable by the user.
 */
static inline uint8_t mavlink_msg_hearbeat_get_brewlink_version(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Decode a hearbeat message into a struct
 *
 * @param msg The message to decode
 * @param hearbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_hearbeat_decode(const mavlink_message_t* msg, mavlink_hearbeat_t* hearbeat)
{
#if MAVLINK_NEED_BYTE_SWAP
	hearbeat->device = mavlink_msg_hearbeat_get_device(msg);
	hearbeat->type = mavlink_msg_hearbeat_get_type(msg);
	hearbeat->mode = mavlink_msg_hearbeat_get_mode(msg);
	hearbeat->brewlink_version = mavlink_msg_hearbeat_get_brewlink_version(msg);
#else
	memcpy(hearbeat, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_HEARBEAT_LEN);
#endif
}
