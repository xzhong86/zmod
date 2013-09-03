// -*- C++ -*-

#ifndef __BASE_WIRE_H__

class inPort;
class outPort;

class baseWire {
    const char *name;
public:
    baseWire(const char *name)
	: name(name) { }

    int addport(inPort *in);
    int addport(outPort *out);

    int connect(outPort *out, inPort *in0 = 0,
		inPort *in1 = 0, inPort *in2 = 0);
    int connect(inPort *in, inPort *in1 = 0,
		inPort *in2 = 0, inPort *in3 = 0);
};

template <typename T>
class pkgWire : public baseWire {
    T val;
public:
    pkgWire(const char *name) : baseWire(name) {}
    T read(inPort &in) {
	return val;
    }
    void write(outPort &out, T v) {
	val = v;
    }
};

typedef pkgWire<unsigned int>       Wire32b;
typedef pkgWire<unsigned long long> Wire64b;

#endif
