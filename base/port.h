// -*- C++ -*-

#ifndef __BASE_WIRE_H__

class baseWire;

class inPort {
    const char *name;
    baseWire *wire;
public:
    inPort(const char *name)
	: name(name) { }
    int connect(baseWire *w);
};
class outPort {
    const char *name;
    baseWire *wire;
public:
    outPort(const char *name)
	: name(name) { }
    int connect(baseWire *w);
};

template <typename T>
class pkgInPort : public inPort {
    void operator = (T v) { }	// Can't write
public:
    operator T ();    // read
};

template <typename T>
class pkgOutPort : public OutPort {
    operator T ();    // Can't read
public:
    void operator = (T v) { }	// write
};

typedef pkgInPort<unsigned int> inPort32;
typedef pkgOutPort<unsigned int> outPort32;

#endif
