TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    readonly/main.cpp \
    readonly/PriceTableADT.cpp \
    readonly/UBike.cpp \
    readonly/UBikeHashTableADT.cpp \
    readonly/UBikeHeapADT.cpp \
    readonly/UBikeSystemADT.cpp \
    PriceTableIMP.cpp \
    UBikeHashTableIMP.cpp \
    UBikeHeapIMP.cpp \
    UBikeSystemIMP.cpp

DISTFILES += \
    Final.cbp \
    Final.layout \
    readonly/tc1/ans.out \
    readonly/tc1/cm.in \
    readonly/tc1/map.in \
    readonly/tc2/ans.out \
    readonly/tc2/cm.in \
    readonly/tc2/map.in \
    readonly/tc3/ans.out \
    readonly/tc3/cm.in \
    readonly/tc3/map.in \
    Final.cscope_file_list \
    Final.depend

HEADERS += \
    readonly/ConstParams.h \
    readonly/PriceTableADT.h \
    readonly/UBike.h \
    readonly/UBikeHashTableADT.h \
    readonly/UBikeHeapADT.h \
    readonly/UBikeSystemADT.h \
    PriceTableIMP.h \
    UBikeHashTableIMP.h \
    UBikeHeapIMP.h \
    UBikeSystemIMP.h
