#ifndef ANALYZER_PROTOCOL_AYIYA_AYIYA_H
#define ANALYZER_PROTOCOL_AYIYA_AYIYA_H

#include "ayiya_pac.h"

namespace analyzer { namespace ayiya {

class AYIYA_Analyzer : public analyzer::Analyzer {
public:
	explicit AYIYA_Analyzer(Connection* conn);
	virtual ~AYIYA_Analyzer();

	virtual void Done();
	virtual void DeliverPacket(uint64_t len, const u_char* data, bool orig,
					uint64_t seq, const IP_Hdr* ip, uint64_t caplen);

	static analyzer::Analyzer* Instantiate(Connection* conn)
		{ return new AYIYA_Analyzer(conn); }

protected:
	binpac::AYIYA::AYIYA_Conn* interp;
};

} } // namespace analyzer::* 

#endif
