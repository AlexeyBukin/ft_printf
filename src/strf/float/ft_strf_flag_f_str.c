/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_f_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:49:15 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/08 13:54:15 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*float_get_str(t_strflags *flags, long double d)
{
	(void)flags;
	(void)d;
	return (ft_strdup("0.0"));
}

char	g_dg[64][65] =
{ \
	"1000000000000000000000000000000000000000000000000000000000000000", \
	"0500000000000000000000000000000000000000000000000000000000000000", \
	"0250000000000000000000000000000000000000000000000000000000000000", \
	"0125000000000000000000000000000000000000000000000000000000000000", \
	"0062500000000000000000000000000000000000000000000000000000000000", \
	"0031250000000000000000000000000000000000000000000000000000000000", \
	"0015625000000000000000000000000000000000000000000000000000000000", \
	"0007812500000000000000000000000000000000000000000000000000000000", \
	"0003906250000000000000000000000000000000000000000000000000000000", \
	"0001953125000000000000000000000000000000000000000000000000000000", \
	"0000976562500000000000000000000000000000000000000000000000000000", \
	"0000488281250000000000000000000000000000000000000000000000000000", \
	"0000244140625000000000000000000000000000000000000000000000000000", \
	"0000122070312500000000000000000000000000000000000000000000000000", \
	"0000061035156250000000000000000000000000000000000000000000000000", \
	"0000030517578125000000000000000000000000000000000000000000000000", \
	"0000015258789062500000000000000000000000000000000000000000000000", \
	"0000007629394531250000000000000000000000000000000000000000000000", \
	"0000003814697265625000000000000000000000000000000000000000000000", \
	"0000001907348632812500000000000000000000000000000000000000000000", \
	"0000000953674316406250000000000000000000000000000000000000000000", \
	"0000000476837158203125000000000000000000000000000000000000000000", \
	"0000000238418579101562500000000000000000000000000000000000000000", \
	"0000000119209289550781250000000000000000000000000000000000000000", \
	"0000000059604644775390625000000000000000000000000000000000000000", \
	"0000000029802322387695312500000000000000000000000000000000000000", \
	"0000000014901161193847656250000000000000000000000000000000000000", \
	"0000000007450580596923828125000000000000000000000000000000000000", \
	"0000000003725290298461914062500000000000000000000000000000000000", \
	"0000000001862645149230957031250000000000000000000000000000000000", \
	"0000000000931322574615478515625000000000000000000000000000000000", \
	"0000000000465661287307739257812500000000000000000000000000000000", \
	"0000000000232830643653869628906250000000000000000000000000000000", \
	"0000000000116415321826934814453125000000000000000000000000000000", \
	"0000000000058207660913467407226562500000000000000000000000000000", \
	"0000000000029103830456733703613281250000000000000000000000000000", \
	"0000000000014551915228366851806640625000000000000000000000000000", \
	"0000000000007275957614183425903320312500000000000000000000000000", \
	"0000000000003637978807091712951660156250000000000000000000000000", \
	"0000000000001818989403545856475830078125000000000000000000000000", \
	"0000000000000909494701772928237915039062500000000000000000000000", \
	"0000000000000454747350886464118957519531250000000000000000000000", \
	"0000000000000227373675443232059478759765625000000000000000000000", \
	"0000000000000113686837721616029739379882812500000000000000000000", \
	"0000000000000056843418860808014869689941406250000000000000000000", \
	"0000000000000028421709430404007434844970703125000000000000000000", \
	"0000000000000014210854715202003717422485351562500000000000000000", \
	"0000000000000007105427357601001858711242675781250000000000000000", \
	"0000000000000003552713678800500929355621337890625000000000000000", \
	"0000000000000001776356839400250464677810668945312500000000000000", \
	"0000000000000000888178419700125232338905334472656250000000000000", \
	"0000000000000000444089209850062616169452667236328125000000000000", \
	"0000000000000000222044604925031308084726333618164062500000000000", \
	"0000000000000000111022302462515654042363166809082031250000000000", \
	"0000000000000000055511151231257827021181583404541015625000000000", \
	"0000000000000000027755575615628913510590791702270507812500000000", \
	"0000000000000000013877787807814456755295395851135253906250000000", \
	"0000000000000000006938893903907228377647697925567626953125000000", \
	"0000000000000000003469446951953614188823848962783813476562500000", \
	"0000000000000000001734723475976807094411924481391906738281250000", \
	"0000000000000000000867361737988403547205962240695953369140625000", \
	"0000000000000000000433680868994201773602981120347976684570312500", \
	"0000000000000000000216840434497100886801490560173988342285156250", \
	"0000000000000000000108420217248550443400745280086994171142578125"  \
};
