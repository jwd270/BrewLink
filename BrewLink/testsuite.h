/** @file
 *	@brief MAVLink comm protocol testsuite generated from BrewLink.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef BREWLINK_TESTSUITE_H
#define BREWLINK_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_BrewLink(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_BrewLink(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_hearbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_hearbeat_t packet_in = {
		5,
	}72,
	}139,
	}3,
	};
	mavlink_hearbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.device = packet_in.device;
        	packet1.type = packet_in.type;
        	packet1.mode = packet_in.mode;
        	packet1.brewlink_version = packet_in.brewlink_version;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hearbeat_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_hearbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hearbeat_pack(system_id, component_id, &msg , packet1.device , packet1.type , packet1.mode );
	mavlink_msg_hearbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hearbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.device , packet1.type , packet1.mode );
	mavlink_msg_hearbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_hearbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hearbeat_send(MAVLINK_COMM_1 , packet1.device , packet1.type , packet1.mode );
	mavlink_msg_hearbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_temperature_reading(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_temperature_reading_t packet_in = {
		17235,
	}139,
	};
	mavlink_temperature_reading_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.temp = packet_in.temp;
        	packet1.tempType = packet_in.tempType;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_temperature_reading_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_temperature_reading_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_temperature_reading_pack(system_id, component_id, &msg , packet1.temp , packet1.tempType );
	mavlink_msg_temperature_reading_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_temperature_reading_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.temp , packet1.tempType );
	mavlink_msg_temperature_reading_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_temperature_reading_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_temperature_reading_send(MAVLINK_COMM_1 , packet1.temp , packet1.tempType );
	mavlink_msg_temperature_reading_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_battery_voltage(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_battery_voltage_t packet_in = {
		17235,
	}139,
	};
	mavlink_battery_voltage_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.battVolts = packet_in.battVolts;
        	packet1.scale = packet_in.scale;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_battery_voltage_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_battery_voltage_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_battery_voltage_pack(system_id, component_id, &msg , packet1.battVolts , packet1.scale );
	mavlink_msg_battery_voltage_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_battery_voltage_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.battVolts , packet1.scale );
	mavlink_msg_battery_voltage_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_battery_voltage_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_battery_voltage_send(MAVLINK_COMM_1 , packet1.battVolts , packet1.scale );
	mavlink_msg_battery_voltage_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_BrewLink(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_hearbeat(system_id, component_id, last_msg);
	mavlink_test_temperature_reading(system_id, component_id, last_msg);
	mavlink_test_battery_voltage(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // BREWLINK_TESTSUITE_H
