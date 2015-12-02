#ifndef k6_PACKET_H
# define K6_PACKET_H

# include <k6_file.h>

typedef struct s_pkt			*t_pkt;
typedef struct u_net_lay		*t_net_lay;
typedef struct u_trans_lay		*t_trans_lay;
typedef struct u_session_lay	*t_session_lay;
typedef struct u_pres_lay		*t_pres_lay;
typedef struct u_app_lay		*t_app_lay;

typedef struct t_arp			*arp;

/*
 * PACKET
 * ============================================================================
 */

struct				s_class_pkt
{
	t_pkt			*self;
	t_pkt			*(*new)();
	void			(*set)
		  ();
	char			(*forge_lnk)();
	char			(*forge_net)();
};

t_class_pkt			*get_class_packet();
t_pkt				*new_packet();

struct				s_pkt
{
	t_link_ley		*link;
	t_net_lay		*net;
	t_trans_lay		*trans;
	t_session_lay	*session;
	t_pres_lay		*pres;
	t_app_lay		*app;
	t_blk			*blk;
};

/*
 * PACKET FIELDS (OSI LAYERS)
 * ============================================================================
 */
union				u_net_lay
{
	t_arp			*arp;
	t_ip			*ip;
};

union				u_link_lay
{
	t_ether			*ether;
};

union				u_trans_lay
{
};

union				u_session_lay
{
};

union				u_pres_lay
{
};

union				u_app_lay
{
};

/*
 * PROTOCOLS
 * ============================================================================
 */


#endif
