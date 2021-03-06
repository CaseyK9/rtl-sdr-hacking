#ifndef	__FM_CFG_H__
#define	__FM_CFG_H__

#define DEFAULT_SAMPLE_RATE             24000
#define DEFAULT_BUF_LENGTH              (1 * 16384)
#define MAXIMUM_OVERSAMPLE              16
#define MAXIMUM_BUF_LENGTH              (MAXIMUM_OVERSAMPLE * DEFAULT_BUF_LENGTH)
#define AUTO_GAIN                       -100
#define BUFFER_DUMP                     4096

#define FREQUENCIES_LIMIT               1000


#endif

