Attribute VB_Name = "modMMReg"
Option Explicit


Public Const MM_MICROSOFT = 1           ' Microsoft Corporation '
Public Const MM_CREATIVE = 2           ' Creative Labs, Inc. '
Public Const MM_MEDIAVISION = 3           ' Media Vision, Inc. '
Public Const MM_FUJITSU = 4           ' Fujitsu Corp. '
Public Const MM_PRAGMATRAX = 5           ' PRAGMATRAX Software '
Public Const MM_CYRIX = 6           ' Cyrix Corporation '
Public Const MM_PHILIPS_SPEECH_PROCESSING = 7           ' Philips Speech Processing '
Public Const MM_NETXL = 8           ' NetXL, Inc. '
Public Const MM_ZYXEL = 9           ' ZyXEL Communications, Inc. '
Public Const MM_BECUBED = 10          ' BeCubed Software Inc. '
Public Const MM_AARDVARK = 11          ' Aardvark Computer Systems, Inc. '
Public Const MM_BINTEC = 12          ' Bin Tec Communications GmbH '
Public Const MM_HEWLETT_PACKARD = 13          ' Hewlett-Packard Company '
Public Const MM_ACULAB = 14          ' Aculab plc '
Public Const MM_FAITH = 15          ' Faith,Inc. '
Public Const MM_MITEL = 16          ' Mitel Corporation '
Public Const MM_QUANTUM3D = 17          ' Quantum3D, Inc. '
Public Const MM_SNI = 18          ' Siemens-Nixdorf '
Public Const MM_EMU = 19          ' E-mu Systems, Inc. '
Public Const MM_ARTISOFT = 20          ' Artisoft, Inc. '
Public Const MM_TURTLE_BEACH = 21          ' Turtle Beach, Inc. '
Public Const MM_IBM = 22          ' IBM Corporation '
Public Const MM_VOCALTEC = 23          ' Vocaltec Ltd. '
Public Const MM_ROLAND = 24          ' Roland '
Public Const MM_DSP_SOLUTIONS = 25          ' DSP Solutions, Inc. '
Public Const MM_NEC = 26          ' NEC '
Public Const MM_ATI = 27          ' ATI Technologies Inc. '
Public Const MM_WANGLABS = 28          ' Wang Laboratories, Inc. '
Public Const MM_TANDY = 29          ' Tandy Corporation '
Public Const MM_VOYETRA = 30          ' Voyetra '
Public Const MM_ANTEX = 31          ' Antex Electronics Corporation '
Public Const MM_ICL_PS = 32          ' ICL Personal Systems '
Public Const MM_INTEL = 33          ' Intel Corporation '
Public Const MM_GRAVIS = 34          ' Advanced Gravis '
Public Const MM_VAL = 35          ' Video Associates Labs, Inc. '
Public Const MM_INTERACTIVE = 36          ' InterActive Inc. '
Public Const MM_YAMAHA = 37          ' Yamaha Corporation of America '
Public Const MM_EVEREX = 38          ' Everex Systems, Inc. '
Public Const MM_ECHO = 39          ' Echo Speech Corporation '
Public Const MM_SIERRA = 40          ' Sierra Semiconductor Corp '
Public Const MM_CAT = 41          ' Computer Aided Technologies '
Public Const MM_APPS = 42          ' APPS Software International '
Public Const MM_DSP_GROUP = 43          ' DSP Group, Inc. '
Public Const MM_MELABS = 44          ' microEngineering Labs '
Public Const MM_COMPUTER_FRIENDS = 45          ' Computer Friends, Inc. '
Public Const MM_ESS = 46          ' ESS Technology '
Public Const MM_AUDIOFILE = 47          ' Audio, Inc. '
Public Const MM_MOTOROLA = 48          ' Motorola, Inc. '
Public Const MM_CANOPUS = 49          ' Canopus, co., Ltd. '
Public Const MM_EPSON = 50          ' Seiko Epson Corporation '
Public Const MM_TRUEVISION = 51          ' Truevision '
Public Const MM_AZTECH = 52          ' Aztech Labs, Inc. '
Public Const MM_VIDEOLOGIC = 53          ' Videologic '
Public Const MM_SCALACS = 54          ' SCALACS '
Public Const MM_KORG = 55          ' Korg Inc. '
Public Const MM_APT = 56          ' Audio Processing Technology '
Public Const MM_ICS = 57          ' Integrated Circuit Systems, Inc. '
Public Const MM_ITERATEDSYS = 58          ' Iterated Systems, Inc. '
Public Const MM_METHEUS = 59          ' Metheus '
Public Const MM_LOGITECH = 60          ' Logitech, Inc. '
Public Const MM_WINNOV = 61          ' Winnov, Inc. '
Public Const MM_NCR = 62          ' NCR Corporation '
Public Const MM_EXAN = 63          ' EXAN '
Public Const MM_AST = 64          ' AST Research Inc. '
Public Const MM_WILLOWPOND = 65          ' Willow Pond Corporation '
Public Const MM_SONICFOUNDRY = 66          ' Sonic Foundry '
Public Const MM_VITEC = 67          ' Vitec Multimedia '
Public Const MM_MOSCOM = 68          ' MOSCOM Corporation '
Public Const MM_SILICONSOFT = 69          ' Silicon Soft, Inc. '
Public Const MM_TERRATEC = 70          ' TerraTec Electronic GmbH '
Public Const MM_MEDIASONIC = 71          ' MediaSonic Ltd. '
Public Const MM_SANYO = 72          ' SANYO Electric Co., Ltd. '
Public Const MM_SUPERMAC = 73          ' Supermac '
Public Const MM_AUDIOPT = 74          ' Audio Processing Technology '
Public Const MM_NOGATECH = 75          ' NOGATECH Ltd. '
Public Const MM_SPEECHCOMP = 76          ' Speech Compression '
Public Const MM_AHEAD = 77          ' Ahead, Inc. '
Public Const MM_DOLBY = 78          ' Dolby Laboratories '
Public Const MM_OKI = 79          ' OKI '
Public Const MM_AURAVISION = 80          ' AuraVision Corporation '
Public Const MM_OLIVETTI = 81          ' Ing C. Olivetti & C., S.p.A. '
Public Const MM_IOMAGIC = 82          ' I/O Magic Corporation '
Public Const MM_MATSUSHITA = 83          ' Matsushita Electric Industrial Co., Ltd. '
Public Const MM_CONTROLRES = 84          ' Control Resources Limited '
Public Const MM_XEBEC = 85          ' Xebec Multimedia Solutions Limited '
Public Const MM_NEWMEDIA = 86          ' New Media Corporation '
Public Const MM_NMS = 87          ' Natural MicroSystems '
Public Const MM_LYRRUS = 88          ' Lyrrus Inc. '
Public Const MM_COMPUSIC = 89          ' Compusic '
Public Const MM_OPTI = 90          ' OPTi Computers Inc. '
Public Const MM_ADLACC = 91          ' Adlib Accessories Inc. '
Public Const MM_COMPAQ = 92          ' Compaq Computer Corp. '
Public Const MM_DIALOGIC = 93          ' Dialogic Corporation '
Public Const MM_INSOFT = 94          ' InSoft, Inc. '
Public Const MM_MPTUS = 95          ' M.P. Technologies, Inc. '
Public Const MM_WEITEK = 96          ' Weitek '
Public Const MM_LERNOUT_AND_HAUSPIE = 97          ' Lernout & Hauspie '
Public Const MM_QCIAR = 98          ' Quanta Computer Inc. '
Public Const MM_APPLE = 99          ' Apple Computer, Inc. '
Public Const MM_DIGITAL = 100         ' Digital Equipment Corporation '
Public Const MM_MOTU = 101         ' Mark of the Unicorn '
Public Const MM_WORKBIT = 102         ' Workbit Corporation '
Public Const MM_OSITECH = 103         ' Ositech Communications Inc. '
Public Const MM_MIRO = 104         ' miro Computer Products AG '
Public Const MM_CIRRUSLOGIC = 105         ' Cirrus Logic '
Public Const MM_ISOLUTION = 106         ' ISOLUTION  B.V. '
Public Const MM_HORIZONS = 107         ' Horizons Technology, Inc. '
Public Const MM_CONCEPTS = 108         ' Computer Concepts Ltd. '
Public Const MM_VTG = 109         ' Voice Technologies Group, Inc. '
Public Const MM_RADIUS = 110         ' Radius '
Public Const MM_ROCKWELL = 111         ' Rockwell International '
Public Const MM_XYZ = 112         ' Co. XYZ for testing '
Public Const MM_OPCODE = 113         ' Opcode Systems '
Public Const MM_VOXWARE = 114         ' Voxware Inc. '
Public Const MM_NORTHERN_TELECOM = 115         ' Northern Telecom Limited '
Public Const MM_APICOM = 116         ' APICOM '
Public Const MM_GRANDE = 117         ' Grande Software '
Public Const MM_ADDX = 118         ' ADDX '
Public Const MM_WILDCAT = 119         ' Wildcat Canyon Software '
Public Const MM_RHETOREX = 120         ' Rhetorex Inc. '
Public Const MM_BROOKTREE = 121         ' Brooktree Corporation '
Public Const MM_ENSONIQ = 125         ' ENSONIQ Corporation '
Public Const MM_FAST = 126         ' FAST Multimedia AG '
Public Const MM_NVIDIA = 127         ' NVidia Corporation '
Public Const MM_OKSORI = 128         ' OKSORI Co., Ltd. '
Public Const MM_DIACOUSTICS = 129         ' DiAcoustics, Inc. '
Public Const MM_GULBRANSEN = 130         ' Gulbransen, Inc. '
Public Const MM_KAY_ELEMETRICS = 131         ' Kay Elemetrics, Inc. '
Public Const MM_CRYSTAL = 132         ' Crystal Semiconductor Corporation '
Public Const MM_SPLASH_STUDIOS = 133         ' Splash Studios '
Public Const MM_QUARTERDECK = 134         ' Quarterdeck Corporation '
Public Const MM_TDK = 135         ' TDK Corporation '
Public Const MM_DIGITAL_AUDIO_LABS = 136         ' Digital Audio Labs, Inc. '
Public Const MM_SEERSYS = 137         ' Seer Systems, Inc. '
Public Const MM_PICTURETEL = 138         ' PictureTel Corporation '
Public Const MM_ATT_MICROELECTRONICS = 139         ' AT&T Microelectronics '
Public Const MM_OSPREY = 140         ' Osprey Technologies, Inc. '
Public Const MM_MEDIATRIX = 141         ' Mediatrix Peripherals '
Public Const MM_SOUNDESIGNS = 142         ' SounDesignS M.C.S. Ltd. '
Public Const MM_ALDIGITAL = 143         ' A.L. Digital Ltd. '
Public Const MM_SPECTRUM_SIGNAL_PROCESSING = 144         ' Spectrum Signal Processing, Inc. '
Public Const MM_ECS = 145         ' Electronic Courseware Systems, Inc. '
Public Const MM_AMD = 146         ' AMD '
Public Const MM_COREDYNAMICS = 147         ' Core Dynamics '
Public Const MM_CANAM = 148         ' CANAM Computers '
Public Const MM_SOFTSOUND = 149         ' Softsound, Ltd. '
Public Const MM_NORRIS = 150         ' Norris Communications, Inc. '
Public Const MM_DDD = 151         ' Danka Data Devices '
Public Const MM_EUPHONICS = 152         ' EuPhonics '
Public Const MM_PRECEPT = 153         ' Precept Software, Inc. '
Public Const MM_CRYSTAL_NET = 154         ' Crystal Net Corporation '
Public Const MM_CHROMATIC = 155         ' Chromatic Research, Inc. '
Public Const MM_VOICEINFO = 156         ' Voice Information Systems, Inc. '
Public Const MM_VIENNASYS = 157         ' Vienna Systems '
Public Const MM_CONNECTIX = 158         ' Connectix Corporation '
Public Const MM_GADGETLABS = 159         ' Gadget Labs LLC '
Public Const MM_FRONTIER = 160         ' Frontier Design Group LLC '
Public Const MM_VIONA = 161         ' Viona Development GmbH '
Public Const MM_CASIO = 162         ' Casio Computer Co., LTD '
Public Const MM_DIAMONDMM = 163         ' Diamond Multimedia '
Public Const MM_S3 = 164         ' S3 '
Public Const MM_DVISION = 165         ' D-Vision Systems, Inc. '
Public Const MM_NETSCAPE = 166         ' Netscape Communications '
Public Const MM_SOUNDSPACE = 167         ' Soundspace Audio '
Public Const MM_VANKOEVERING = 168         ' VanKoevering Company '
Public Const MM_QTEAM = 169         ' Q-Team '
Public Const MM_ZEFIRO = 170         ' Zefiro Acoustics '
Public Const MM_STUDER = 171         ' Studer Professional Audio AG '
Public Const MM_FRAUNHOFER_IIS = 172         ' Fraunhofer IIS '
Public Const MM_QUICKNET = 173         ' Quicknet Technologies '
Public Const MM_ALARIS = 174         ' Alaris, Inc. '
Public Const MM_SICRESOURCE = 175         ' SIC Resource Inc. '
Public Const MM_NEOMAGIC = 176         ' NeoMagic Corporation '
Public Const MM_MERGING_TECHNOLOGIES = 177         ' Merging Technologies S.A. '
Public Const MM_XIRLINK = 178         ' Xirlink, Inc. '
Public Const MM_COLORGRAPH = 179         ' Colorgraph (UK) Ltd '
Public Const MM_OTI = 180         ' Oak Technology, Inc. '
Public Const MM_AUREAL = 181         ' Aureal Semiconductor '
Public Const MM_VIVO = 182         ' Vivo Software '
Public Const MM_SHARP = 183         ' Sharp '
Public Const MM_LUCENT = 184         ' Lucent Technologies '
Public Const MM_ATT = 185         ' AT&T Labs, Inc. '
Public Const MM_SUNCOM = 186         ' Sun Communications, Inc. '
Public Const MM_SORVIS = 187         ' Sorenson Vision '
Public Const MM_INVISION = 188         ' InVision Interactive '
Public Const MM_BERKOM = 189         ' Deutsche Telekom Berkom GmbH '
Public Const MM_MARIAN = 190         ' Marian GbR Leipzig '
Public Const MM_DPSINC = 191         ' Digital Processing Systems, Inc. '
Public Const MM_BCB = 192         ' BCB Holdings Inc. '
Public Const MM_MOTIONPIXELS = 193         ' Motion Pixels '
Public Const MM_QDESIGN = 194         ' QDesign Corporation '
Public Const MM_NMP = 195         ' Nokia Mobile Phones '
Public Const MM_DATAFUSION = 196         ' DataFusion Systems (Pty) (Ltd) '
Public Const MM_DUCK = 197         ' The Duck Corporation '
Public Const MM_FTR = 198         ' Future Technology Resources Pty Ltd '
Public Const MM_BERCOS = 199         ' BERCOS GmbH '
Public Const MM_ONLIVE = 200         ' OnLive! Technologies, Inc. '
Public Const MM_SIEMENS_SBC = 201         ' Siemens Business Communications Systems '
Public Const MM_TERALOGIC = 202         ' TeraLogic, Inc. '
Public Const MM_PHONET = 203         ' PhoNet Communications Ltd. '
Public Const MM_WINBOND = 204         ' Winbond Electronics Corp '
Public Const MM_VIRTUALMUSIC = 205         ' Virtual Music, Inc. '
Public Const MM_ENET = 206         ' e-Net, Inc. '
Public Const MM_GUILLEMOT = 207         ' Guillemot International '
Public Const MM_EMAGIC = 208         ' Emagic Soft- und Hardware GmbH '
Public Const MM_MWM = 209         ' MWM Acoustics LLC '
Public Const MM_PACIFICRESEARCH = 210         ' Pacific Research and Engineering Corporation '
Public Const MM_SIPROLAB = 211         ' Sipro Lab Telecom Inc. '
Public Const MM_LYNX = 212         ' Lynx Studio Technology, Inc. '
Public Const MM_SPECTRUM_PRODUCTIONS = 213         ' Spectrum Productions '
Public Const MM_DICTAPHONE = 214         ' Dictaphone Corporation '
Public Const MM_QUALCOMM = 215         ' QUALCOMM, Inc. '
Public Const MM_RZS = 216         ' Ring Zero Systems, Inc '
Public Const MM_AUDIOSCIENCE = 217         ' AudioScience Inc. '
Public Const MM_PINNACLE = 218         ' Pinnacle Systems, Inc. '
Public Const MM_EES = 219         ' EES Technik für Musik GmbH '
Public Const MM_HAFTMANN = 220         ' haftmann#software '
Public Const MM_LUCID = 221         ' Lucid Technology, Symetrix Inc. '
Public Const MM_HEADSPACE = 222         ' Headspace, Inc '
Public Const MM_UNISYS = 223         ' UNISYS CORPORATION '
Public Const MM_LUMINOSITI = 224         ' Luminositi, Inc. '
Public Const MM_ACTIVEVOICE = 225         ' ACTIVE VOICE CORPORATION '
Public Const MM_DTS = 226         ' Digital Theater Systems, Inc. '
Public Const MM_DIGIGRAM = 227         ' DIGIGRAM '
Public Const MM_SOFTLAB_NSK = 228         ' Softlab-Nsk '
Public Const MM_FORTEMEDIA = 229         ' ForteMedia, Inc '
Public Const MM_SONORUS = 230         ' Sonorus, Inc. '
Public Const MM_ARRAY = 231         ' Array Microsystems, Inc. '
Public Const MM_DATARAN = 232         ' Data Translation, Inc. '
Public Const MM_I_LINK = 233         ' I-link Worldwide '
Public Const MM_SELSIUS_SYSTEMS = 234         ' Selsius Systems Inc. '
Public Const MM_ADMOS = 235         ' AdMOS Technology, Inc. '
Public Const MM_LEXICON = 236         ' Lexicon Inc. '
Public Const MM_SGI = 237         ' Silicon Graphics Inc. '
Public Const MM_IPI = 238         ' Interactive Product Inc. '
Public Const MM_ICE = 239         ' IC Ensemble, Inc. '
Public Const MM_VQST = 240         ' ViewQuest Technologies Inc. '
Public Const MM_ETEK = 241         ' eTEK Labs Inc. '
Public Const MM_CS = 242         ' Consistent Software '
Public Const MM_ALESIS = 243         ' Alesis Studio Electronics '
Public Const MM_INTERNET = 244         ' INTERNET Corporation '
Public Const MM_SONY = 245         ' Sony Corporation '
Public Const MM_HYPERACTIVE = 246         ' Hyperactive Audio Systems, Inc. '
Public Const MM_UHER_INFORMATIC = 247         ' UHER informatic GmbH '
Public Const MM_SYDEC_NV = 248         ' Sydec NV '
Public Const MM_FLEXION = 249         ' Flexion Systems Ltd. '
Public Const MM_VIA = 250         ' Via Technologies, Inc. '
Public Const MM_MICRONAS = 251         ' Micronas Semiconductors, Inc. '
Public Const MM_ANALOGDEVICES = 252         ' Analog Devices, Inc. '
Public Const MM_HP = 253         ' Hewlett Packard Company '
Public Const MM_MATROX_DIV = 254         ' Matrox '
Public Const MM_QUICKAUDIO = 255         ' Quick Audio, GbR '
Public Const MM_YOUCOM = 256         ' You/Com Audiocommunicatie BV '
Public Const MM_RICHMOND = 257         ' Richmond Sound Design Ltd. '
Public Const MM_IODD = 258         ' I-O Data Device, Inc. '
Public Const MM_ICCC = 259         ' ICCC A/S '
Public Const MM_3COM = 260         ' 3COM Corporation '
Public Const MM_MALDEN = 261         ' Malden Electronics Ltd. '
Public Const MM_3DFX = 262         ' 3Dfx Interactive, Inc. '
Public Const MM_MINDMAKER = 263         ' Mindmaker, Inc. '
Public Const MM_TELEKOL = 264         ' Telekol Corp. '
Public Const MM_ST_MICROELECTRONICS = 265         ' ST Microelectronics '
Public Const MM_ALGOVISION = 266         ' Algo Vision Systems GmbH '

Public Const MM_UNMAPPED = &HFFFF      ' extensible MID mapping '

Public Const MM_PID_UNMAPPED = MM_UNMAPPED ' extensible PID mapping '



Public Const MM_MIDI_MAPPER = 1       '  Midi Mapper  '
Public Const MM_WAVE_MAPPER = 2       '  Wave Mapper  '
Public Const MM_SNDBLST_MIDIOUT = 3       '  Sound Blaster MIDI output port  '
Public Const MM_SNDBLST_MIDIIN = 4       '  Sound Blaster MIDI input port  '
Public Const MM_SNDBLST_SYNTH = 5       '  Sound Blaster internal synth  '
Public Const MM_SNDBLST_WAVEOUT = 6       '  Sound Blaster waveform output  '
Public Const MM_SNDBLST_WAVEIN = 7       '  Sound Blaster waveform input  '
Public Const MM_ADLIB = 9       '  Ad Lib Compatible synth  '
Public Const MM_MPU401_MIDIOUT = 10      '  MPU 401 compatible MIDI output port  '
Public Const MM_MPU401_MIDIIN = 11      '  MPU 401 compatible MIDI input port  '
Public Const MM_PC_JOYSTICK = 12      '  Joystick adapter  '


Public Const MM_PCSPEAKER_WAVEOUT = 13      '  PC speaker waveform output  '
Public Const MM_MSFT_WSS_WAVEIN = 14      '  MS Audio Board waveform input  '
Public Const MM_MSFT_WSS_WAVEOUT = 15      '  MS Audio Board waveform output  '
Public Const MM_MSFT_WSS_FMSYNTH_STEREO = 16      '  MS Audio Board  Stereo FM synth  '
Public Const MM_MSFT_WSS_MIXER = 17      '  MS Audio Board Mixer Driver  '
Public Const MM_MSFT_WSS_OEM_WAVEIN = 18      '  MS OEM Audio Board waveform input  '
Public Const MM_MSFT_WSS_OEM_WAVEOUT = 19      '  MS OEM Audio Board waveform output  '
Public Const MM_MSFT_WSS_OEM_FMSYNTH_STEREO = 20      '  MS OEM Audio Board Stereo FM Synth  '
Public Const MM_MSFT_WSS_AUX = 21      '  MS Audio Board Aux. Port  '
Public Const MM_MSFT_WSS_OEM_AUX = 22      '  MS OEM Audio Aux Port  '
Public Const MM_MSFT_GENERIC_WAVEIN = 23      '  MS Vanilla driver waveform input  '
Public Const MM_MSFT_GENERIC_WAVEOUT = 24      '  MS Vanilla driver wavefrom output  '
Public Const MM_MSFT_GENERIC_MIDIIN = 25      '  MS Vanilla driver MIDI in  '
Public Const MM_MSFT_GENERIC_MIDIOUT = 26      '  MS Vanilla driver MIDI  external out  '
Public Const MM_MSFT_GENERIC_MIDISYNTH = 27      '  MS Vanilla driver MIDI synthesizer  '
Public Const MM_MSFT_GENERIC_AUX_LINE = 28      '  MS Vanilla driver aux (line in)  '
Public Const MM_MSFT_GENERIC_AUX_MIC = 29      '  MS Vanilla driver aux (mic)  '
Public Const MM_MSFT_GENERIC_AUX_CD = 30      '  MS Vanilla driver aux (CD)  '
Public Const MM_MSFT_WSS_OEM_MIXER = 31      '  MS OEM Audio Board Mixer Driver  '
Public Const MM_MSFT_MSACM = 32      '  MS Audio Compression Manager  '
Public Const MM_MSFT_ACM_MSADPCM = 33      '  MS ADPCM Codec  '
Public Const MM_MSFT_ACM_IMAADPCM = 34      '  IMA ADPCM Codec  '
Public Const MM_MSFT_ACM_MSFILTER = 35      '  MS Filter  '
Public Const MM_MSFT_ACM_GSM610 = 36      '  GSM 610 codec  '
Public Const MM_MSFT_ACM_G711 = 37      '  G.711 codec  '
Public Const MM_MSFT_ACM_PCM = 38      '  PCM converter  '

   ' Microsoft Windows Sound System drivers

Public Const MM_WSS_SB16_WAVEIN = 39      '  Sound Blaster 16 waveform input  '
Public Const MM_WSS_SB16_WAVEOUT = 40      '  Sound Blaster 16  waveform output  '
Public Const MM_WSS_SB16_MIDIIN = 41      '  Sound Blaster 16 midi-in  '
Public Const MM_WSS_SB16_MIDIOUT = 42      '  Sound Blaster 16 midi out  '
Public Const MM_WSS_SB16_SYNTH = 43      '  Sound Blaster 16 FM Synthesis  '
Public Const MM_WSS_SB16_AUX_LINE = 44      '  Sound Blaster 16 aux (line in)  '
Public Const MM_WSS_SB16_AUX_CD = 45      '  Sound Blaster 16 aux (CD)  '
Public Const MM_WSS_SB16_MIXER = 46      '  Sound Blaster 16 mixer device  '
Public Const MM_WSS_SBPRO_WAVEIN = 47      '  Sound Blaster Pro waveform input  '
Public Const MM_WSS_SBPRO_WAVEOUT = 48      '  Sound Blaster Pro waveform output  '
Public Const MM_WSS_SBPRO_MIDIIN = 49      '  Sound Blaster Pro midi in  '
Public Const MM_WSS_SBPRO_MIDIOUT = 50      '  Sound Blaster Pro midi out  '
Public Const MM_WSS_SBPRO_SYNTH = 51      '  Sound Blaster Pro FM synthesis  '
Public Const MM_WSS_SBPRO_AUX_LINE = 52      '  Sound Blaster Pro aux (line in )  '
Public Const MM_WSS_SBPRO_AUX_CD = 53      '  Sound Blaster Pro aux (CD)  '
Public Const MM_WSS_SBPRO_MIXER = 54      '  Sound Blaster Pro mixer  '
Public Const MM_MSFT_WSS_NT_WAVEIN = 55      '  WSS NT wave in  '
Public Const MM_MSFT_WSS_NT_WAVEOUT = 56      '  WSS NT wave out  '
Public Const MM_MSFT_WSS_NT_FMSYNTH_STEREO = 57      '  WSS NT FM synth  '
Public Const MM_MSFT_WSS_NT_MIXER = 58      '  WSS NT mixer  '
Public Const MM_MSFT_WSS_NT_AUX = 59      '  WSS NT aux  '
Public Const MM_MSFT_SB16_WAVEIN = 60      '  Sound Blaster 16 waveform input  '
Public Const MM_MSFT_SB16_WAVEOUT = 61      '  Sound Blaster 16  waveform output  '
Public Const MM_MSFT_SB16_MIDIIN = 62      '  Sound Blaster 16 midi-in  '
Public Const MM_MSFT_SB16_MIDIOUT = 63      '  Sound Blaster 16 midi out  '
Public Const MM_MSFT_SB16_SYNTH = 64      '  Sound Blaster 16 FM Synthesis  '
Public Const MM_MSFT_SB16_AUX_LINE = 65      '  Sound Blaster 16 aux (line in)  '
Public Const MM_MSFT_SB16_AUX_CD = 66      '  Sound Blaster 16 aux (CD)  '
Public Const MM_MSFT_SB16_MIXER = 67      '  Sound Blaster 16 mixer device  '
Public Const MM_MSFT_SBPRO_WAVEIN = 68      '  Sound Blaster Pro waveform input  '
Public Const MM_MSFT_SBPRO_WAVEOUT = 69      '  Sound Blaster Pro waveform output  '
Public Const MM_MSFT_SBPRO_MIDIIN = 70      '  Sound Blaster Pro midi in  '
Public Const MM_MSFT_SBPRO_MIDIOUT = 71      '  Sound Blaster Pro midi out  '
Public Const MM_MSFT_SBPRO_SYNTH = 72      '  Sound Blaster Pro FM synthesis  '
Public Const MM_MSFT_SBPRO_AUX_LINE = 73      '  Sound Blaster Pro aux (line in)  '
Public Const MM_MSFT_SBPRO_AUX_CD = 74      '  Sound Blaster Pro aux (CD)  '
Public Const MM_MSFT_SBPRO_MIXER = 75      '  Sound Blaster Pro mixer  '

Public Const MM_MSFT_MSOPL_SYNTH = 76      '  Yamaha OPL2/OPL3 compatible FM synthesis '

Public Const MM_MSFT_VMDMS_LINE_WAVEIN = 80     ' Voice Modem Serial Line Wave Input '
Public Const MM_MSFT_VMDMS_LINE_WAVEOUT = 81     ' Voice Modem Serial Line Wave Output '
Public Const MM_MSFT_VMDMS_HANDSET_WAVEIN = 82     ' Voice Modem Serial Handset Wave Input '
Public Const MM_MSFT_VMDMS_HANDSET_WAVEOUT = 83     ' Voice Modem Serial Handset Wave Output '
Public Const MM_MSFT_VMDMW_LINE_WAVEIN = 84     ' Voice Modem Wrapper Line Wave Input '
Public Const MM_MSFT_VMDMW_LINE_WAVEOUT = 85     ' Voice Modem Wrapper Line Wave Output '
Public Const MM_MSFT_VMDMW_HANDSET_WAVEIN = 86     ' Voice Modem Wrapper Handset Wave Input '
Public Const MM_MSFT_VMDMW_HANDSET_WAVEOUT = 87     ' Voice Modem Wrapper Handset Wave Output '
Public Const MM_MSFT_VMDMW_MIXER = 88     ' Voice Modem Wrapper Mixer '
Public Const MM_MSFT_VMDM_GAME_WAVEOUT = 89     ' Voice Modem Game Compatible Wave Device '
Public Const MM_MSFT_VMDM_GAME_WAVEIN = 90     ' Voice Modem Game Compatible Wave Device '

Public Const MM_MSFT_ACM_MSNAUDIO = 91
Public Const MM_MSFT_ACM_MSG723 = 92
Public Const MM_MSFT_ACM_MSRT24 = 93

Public Const MM_MSFT_WDMAUDIO_WAVEOUT = 100    ' Generic id for WDM Audio drivers '
Public Const MM_MSFT_WDMAUDIO_WAVEIN = 101    ' Generic id for WDM Audio drivers '
Public Const MM_MSFT_WDMAUDIO_MIDIOUT = 102    ' Generic id for WDM Audio drivers '
Public Const MM_MSFT_WDMAUDIO_MIDIIN = 103    ' Generic id for WDM Audio drivers '
Public Const MM_MSFT_WDMAUDIO_MIXER = 104    ' Generic id for WDM Audio drivers '
Public Const MM_MSFT_WDMAUDIO_AUX = 105    ' Generic id for WDM Audio drivers '


' MM_CREATIVE product IDs '
Public Const MM_CREATIVE_SB15_WAVEIN = 1       '  SB (r) 1.5 waveform input  '
Public Const MM_CREATIVE_SB20_WAVEIN = 2
Public Const MM_CREATIVE_SBPRO_WAVEIN = 3
Public Const MM_CREATIVE_SBP16_WAVEIN = 4
Public Const MM_CREATIVE_PHNBLST_WAVEIN = 5
Public Const MM_CREATIVE_SB15_WAVEOUT = 101
Public Const MM_CREATIVE_SB20_WAVEOUT = 102
Public Const MM_CREATIVE_SBPRO_WAVEOUT = 103
Public Const MM_CREATIVE_SBP16_WAVEOUT = 104
Public Const MM_CREATIVE_PHNBLST_WAVEOUT = 105
Public Const MM_CREATIVE_MIDIOUT = 201     '  SB (r)  '
Public Const MM_CREATIVE_MIDIIN = 202     '  SB (r)  '
Public Const MM_CREATIVE_FMSYNTH_MONO = 301     '  SB (r)  '
Public Const MM_CREATIVE_FMSYNTH_STEREO = 302     '  SB Pro (r) stereo synthesizer  '
Public Const MM_CREATIVE_MIDI_AWE32 = 303
Public Const MM_CREATIVE_AUX_CD = 401     '  SB Pro (r) aux (CD)  '
Public Const MM_CREATIVE_AUX_LINE = 402     '  SB Pro (r) aux (Line in )  '
Public Const MM_CREATIVE_AUX_MIC = 403     '  SB Pro (r) aux (mic)  '
Public Const MM_CREATIVE_AUX_MASTER = 404
Public Const MM_CREATIVE_AUX_PCSPK = 405
Public Const MM_CREATIVE_AUX_WAVE = 406
Public Const MM_CREATIVE_AUX_MIDI = 407
Public Const MM_CREATIVE_SBPRO_MIXER = 408
Public Const MM_CREATIVE_SB16_MIXER = 409

' MM_MEDIAVISION product IDs '

' Pro Audio Spectrum
Public Const MM_MEDIAVISION_PROAUDIO = &H10
Public Const MM_PROAUD_MIDIOUT = (MM_MEDIAVISION_PROAUDIO + 1)
Public Const MM_PROAUD_MIDIIN = (MM_MEDIAVISION_PROAUDIO + 2)
Public Const MM_PROAUD_SYNTH = (MM_MEDIAVISION_PROAUDIO + 3)
Public Const MM_PROAUD_WAVEOUT = (MM_MEDIAVISION_PROAUDIO + 4)
Public Const MM_PROAUD_WAVEIN = (MM_MEDIAVISION_PROAUDIO + 5)
Public Const MM_PROAUD_MIXER = (MM_MEDIAVISION_PROAUDIO + 6)
Public Const MM_PROAUD_AUX = (MM_MEDIAVISION_PROAUDIO + 7)

' Thunder Board
Public Const MM_MEDIAVISION_THUNDER = &H20
Public Const MM_THUNDER_SYNTH = (MM_MEDIAVISION_THUNDER + 3)
Public Const MM_THUNDER_WAVEOUT = (MM_MEDIAVISION_THUNDER + 4)
Public Const MM_THUNDER_WAVEIN = (MM_MEDIAVISION_THUNDER + 5)
Public Const MM_THUNDER_AUX = (MM_MEDIAVISION_THUNDER + 7)

' Audio Port
Public Const MM_MEDIAVISION_TPORT = &H40
Public Const MM_TPORT_WAVEOUT = (MM_MEDIAVISION_TPORT + 1)
Public Const MM_TPORT_WAVEIN = (MM_MEDIAVISION_TPORT + 2)
Public Const MM_TPORT_SYNTH = (MM_MEDIAVISION_TPORT + 3)

' Pro Audio Spectrum Plus
Public Const MM_MEDIAVISION_PROAUDIO_PLUS = &H50
Public Const MM_PROAUD_PLUS_MIDIOUT = (MM_MEDIAVISION_PROAUDIO_PLUS + 1)
Public Const MM_PROAUD_PLUS_MIDIIN = (MM_MEDIAVISION_PROAUDIO_PLUS + 2)
Public Const MM_PROAUD_PLUS_SYNTH = (MM_MEDIAVISION_PROAUDIO_PLUS + 3)
Public Const MM_PROAUD_PLUS_WAVEOUT = (MM_MEDIAVISION_PROAUDIO_PLUS + 4)
Public Const MM_PROAUD_PLUS_WAVEIN = (MM_MEDIAVISION_PROAUDIO_PLUS + 5)
Public Const MM_PROAUD_PLUS_MIXER = (MM_MEDIAVISION_PROAUDIO_PLUS + 6)
Public Const MM_PROAUD_PLUS_AUX = (MM_MEDIAVISION_PROAUDIO_PLUS + 7)

' Pro Audio Spectrum 16
Public Const MM_MEDIAVISION_PROAUDIO_16 = &H60
Public Const MM_PROAUD_16_MIDIOUT = (MM_MEDIAVISION_PROAUDIO_16 + 1)
Public Const MM_PROAUD_16_MIDIIN = (MM_MEDIAVISION_PROAUDIO_16 + 2)
Public Const MM_PROAUD_16_SYNTH = (MM_MEDIAVISION_PROAUDIO_16 + 3)
Public Const MM_PROAUD_16_WAVEOUT = (MM_MEDIAVISION_PROAUDIO_16 + 4)
Public Const MM_PROAUD_16_WAVEIN = (MM_MEDIAVISION_PROAUDIO_16 + 5)
Public Const MM_PROAUD_16_MIXER = (MM_MEDIAVISION_PROAUDIO_16 + 6)
Public Const MM_PROAUD_16_AUX = (MM_MEDIAVISION_PROAUDIO_16 + 7)

' Pro Audio Studio 16
Public Const MM_MEDIAVISION_PROSTUDIO_16 = &H60
Public Const MM_STUDIO_16_MIDIOUT = (MM_MEDIAVISION_PROSTUDIO_16 + 1)
Public Const MM_STUDIO_16_MIDIIN = (MM_MEDIAVISION_PROSTUDIO_16 + 2)
Public Const MM_STUDIO_16_SYNTH = (MM_MEDIAVISION_PROSTUDIO_16 + 3)
Public Const MM_STUDIO_16_WAVEOUT = (MM_MEDIAVISION_PROSTUDIO_16 + 4)
Public Const MM_STUDIO_16_WAVEIN = (MM_MEDIAVISION_PROSTUDIO_16 + 5)
Public Const MM_STUDIO_16_MIXER = (MM_MEDIAVISION_PROSTUDIO_16 + 6)
Public Const MM_STUDIO_16_AUX = (MM_MEDIAVISION_PROSTUDIO_16 + 7)

' CDPC
Public Const MM_MEDIAVISION_CDPC = &H70
Public Const MM_CDPC_MIDIOUT = (MM_MEDIAVISION_CDPC + 1)
Public Const MM_CDPC_MIDIIN = (MM_MEDIAVISION_CDPC + 2)
Public Const MM_CDPC_SYNTH = (MM_MEDIAVISION_CDPC + 3)
Public Const MM_CDPC_WAVEOUT = (MM_MEDIAVISION_CDPC + 4)
Public Const MM_CDPC_WAVEIN = (MM_MEDIAVISION_CDPC + 5)
Public Const MM_CDPC_MIXER = (MM_MEDIAVISION_CDPC + 6)
Public Const MM_CDPC_AUX = (MM_MEDIAVISION_CDPC + 7)

' Opus MV 1208 Chipsent
Public Const MM_MEDIAVISION_OPUS1208 = &H80
Public Const MM_OPUS401_MIDIOUT = (MM_MEDIAVISION_OPUS1208 + 1)
Public Const MM_OPUS401_MIDIIN = (MM_MEDIAVISION_OPUS1208 + 2)
Public Const MM_OPUS1208_SYNTH = (MM_MEDIAVISION_OPUS1208 + 3)
Public Const MM_OPUS1208_WAVEOUT = (MM_MEDIAVISION_OPUS1208 + 4)
Public Const MM_OPUS1208_WAVEIN = (MM_MEDIAVISION_OPUS1208 + 5)
Public Const MM_OPUS1208_MIXER = (MM_MEDIAVISION_OPUS1208 + 6)
Public Const MM_OPUS1208_AUX = (MM_MEDIAVISION_OPUS1208 + 7)

' Opus MV 1216 chipset
Public Const MM_MEDIAVISION_OPUS1216 = &H90
Public Const MM_OPUS1216_MIDIOUT = (MM_MEDIAVISION_OPUS1216 + 1)
Public Const MM_OPUS1216_MIDIIN = (MM_MEDIAVISION_OPUS1216 + 2)
Public Const MM_OPUS1216_SYNTH = (MM_MEDIAVISION_OPUS1216 + 3)
Public Const MM_OPUS1216_WAVEOUT = (MM_MEDIAVISION_OPUS1216 + 4)
Public Const MM_OPUS1216_WAVEIN = (MM_MEDIAVISION_OPUS1216 + 5)
Public Const MM_OPUS1216_MIXER = (MM_MEDIAVISION_OPUS1216 + 6)
Public Const MM_OPUS1216_AUX = (MM_MEDIAVISION_OPUS1216 + 7)

' MM_CYRIX product IDs '
Public Const MM_CYRIX_XASYNTH = 1
Public Const MM_CYRIX_XAMIDIIN = 2
Public Const MM_CYRIX_XAMIDIOUT = 3
Public Const MM_CYRIX_XAWAVEIN = 4
Public Const MM_CYRIX_XAWAVEOUT = 5
Public Const MM_CYRIX_XAAUX = 6
Public Const MM_CYRIX_XAMIXER = 7

' MM_PHILIPS_SPEECH_PROCESSING products IDs '
Public Const MM_PHILIPS_ACM_LPCBB = 1

' MM_NETXL product IDs '
Public Const MM_NETXL_XLVIDEO = 1

' MM_ZYXEL product IDs '
Public Const MM_ZYXEL_ACM_ADPCM = 1

' MM_AARDVARK product IDs '
Public Const MM_AARDVARK_STUDIO12_WAVEOUT = 1
Public Const MM_AARDVARK_STUDIO12_WAVEIN = 2
Public Const MM_AARDVARK_STUDIO88_WAVEOUT = 3
Public Const MM_AARDVARK_STUDIO88_WAVEIN = 4

' MM_BINTEC product IDs '
Public Const MM_BINTEC_TAPI_WAVE = 1

' MM_HEWLETT_PACKARD product IDs '
Public Const MM_HEWLETT_PACKARD_CU_CODEC = 1

' MM_MITEL product IDs '
Public Const MM_MITEL_TALKTO_LINE_WAVEOUT = 100
Public Const MM_MITEL_TALKTO_LINE_WAVEIN = 101
Public Const MM_MITEL_TALKTO_HANDSET_WAVEOUT = 102
Public Const MM_MITEL_TALKTO_HANDSET_WAVEIN = 103
Public Const MM_MITEL_TALKTO_BRIDGED_WAVEOUT = 104
Public Const MM_MITEL_TALKTO_BRIDGED_WAVEIN = 105
Public Const MM_MITEL_MPA_HANDSET_WAVEOUT = 200
Public Const MM_MITEL_MPA_HANDSET_WAVEIN = 201
Public Const MM_MITEL_MPA_HANDSFREE_WAVEOUT = 202
Public Const MM_MITEL_MPA_HANDSFREE_WAVEIN = 203
Public Const MM_MITEL_MPA_LINE1_WAVEOUT = 204
Public Const MM_MITEL_MPA_LINE1_WAVEIN = 205
Public Const MM_MITEL_MPA_LINE2_WAVEOUT = 206
Public Const MM_MITEL_MPA_LINE2_WAVEIN = 207
Public Const MM_MITEL_MEDIAPATH_WAVEOUT = 300
Public Const MM_MITEL_MEDIAPATH_WAVEIN = 301

'  MM_SNI product IDs '
Public Const MM_SNI_ACM_G721 = 1

' MM_EMU product IDs '
Public Const MM_EMU_APSSYNTH = 1
Public Const MM_EMU_APSMIDIIN = 2
Public Const MM_EMU_APSMIDIOUT = 3
Public Const MM_EMU_APSWAVEIN = 4
Public Const MM_EMU_APSWAVEOUT = 5

' MM_ARTISOFT product IDs '
Public Const MM_ARTISOFT_SBWAVEIN = 1       '  Artisoft sounding Board waveform input  '
Public Const MM_ARTISOFT_SBWAVEOUT = 2       '  Artisoft sounding Board waveform output  '

' MM_TURTLE_BEACH product IDs '
Public Const MM_TBS_TROPEZ_WAVEIN = 37
Public Const MM_TBS_TROPEZ_WAVEOUT = 38
Public Const MM_TBS_TROPEZ_AUX1 = 39
Public Const MM_TBS_TROPEZ_AUX2 = 40
Public Const MM_TBS_TROPEZ_LINE = 41

' MM_IBM product IDs '
Public Const MM_MMOTION_WAVEAUX = 1       '  IBM M-Motion Auxiliary Device  '
Public Const MM_MMOTION_WAVEOUT = 2       '  IBM M-Motion Waveform output  '
Public Const MM_MMOTION_WAVEIN = 3       '  IBM M-Motion  Waveform Input  '
Public Const MM_IBM_PCMCIA_WAVEIN = 11      '  IBM waveform input  '
Public Const MM_IBM_PCMCIA_WAVEOUT = 12      '  IBM Waveform output  '
Public Const MM_IBM_PCMCIA_SYNTH = 13      '  IBM Midi Synthesis  '
Public Const MM_IBM_PCMCIA_MIDIIN = 14      '  IBM external MIDI in  '
Public Const MM_IBM_PCMCIA_MIDIOUT = 15      '  IBM external MIDI out  '
Public Const MM_IBM_PCMCIA_AUX = 16      '  IBM auxiliary control  '
Public Const MM_IBM_THINKPAD200 = 17
Public Const MM_IBM_MWAVE_WAVEIN = 18
Public Const MM_IBM_MWAVE_WAVEOUT = 19
Public Const MM_IBM_MWAVE_MIXER = 20
Public Const MM_IBM_MWAVE_MIDIIN = 21
Public Const MM_IBM_MWAVE_MIDIOUT = 22
Public Const MM_IBM_MWAVE_AUX = 23
Public Const MM_IBM_WC_MIDIOUT = 30
Public Const MM_IBM_WC_WAVEOUT = 31
Public Const MM_IBM_WC_MIXEROUT = 33

' MM_VOCALTEC product IDs '
Public Const MM_VOCALTEC_WAVEOUT = 1
Public Const MM_VOCALTEC_WAVEIN = 2

' MM_ROLAND product IDs '
Public Const MM_ROLAND_RAP10_MIDIOUT = 10      ' MM_ROLAND_RAP10 '
Public Const MM_ROLAND_RAP10_MIDIIN = 11      ' MM_ROLAND_RAP10 '
Public Const MM_ROLAND_RAP10_SYNTH = 12      ' MM_ROLAND_RAP10 '
Public Const MM_ROLAND_RAP10_WAVEOUT = 13      ' MM_ROLAND_RAP10 '
Public Const MM_ROLAND_RAP10_WAVEIN = 14      ' MM_ROLAND_RAP10 '
Public Const MM_ROLAND_MPU401_MIDIOUT = 15
Public Const MM_ROLAND_MPU401_MIDIIN = 16
Public Const MM_ROLAND_SMPU_MIDIOUTA = 17
Public Const MM_ROLAND_SMPU_MIDIOUTB = 18
Public Const MM_ROLAND_SMPU_MIDIINA = 19
Public Const MM_ROLAND_SMPU_MIDIINB = 20
Public Const MM_ROLAND_SC7_MIDIOUT = 21
Public Const MM_ROLAND_SC7_MIDIIN = 22
Public Const MM_ROLAND_SERIAL_MIDIOUT = 23
Public Const MM_ROLAND_SERIAL_MIDIIN = 24
Public Const MM_ROLAND_SCP_MIDIOUT = 38
Public Const MM_ROLAND_SCP_MIDIIN = 39
Public Const MM_ROLAND_SCP_WAVEOUT = 40
Public Const MM_ROLAND_SCP_WAVEIN = 41
Public Const MM_ROLAND_SCP_MIXER = 42
Public Const MM_ROLAND_SCP_AUX = 48

' MM_DSP_SOLUTIONS product IDs '
Public Const MM_DSP_SOLUTIONS_WAVEOUT = 1
Public Const MM_DSP_SOLUTIONS_WAVEIN = 2
Public Const MM_DSP_SOLUTIONS_SYNTH = 3
Public Const MM_DSP_SOLUTIONS_AUX = 4

' MM_NEC product IDs '
Public Const MM_NEC_73_86_SYNTH = 5
Public Const MM_NEC_73_86_WAVEOUT = 6
Public Const MM_NEC_73_86_WAVEIN = 7
Public Const MM_NEC_26_SYNTH = 9
Public Const MM_NEC_MPU401_MIDIOUT = 10
Public Const MM_NEC_MPU401_MIDIIN = 11
Public Const MM_NEC_JOYSTICK = 12

' MM_WANGLABS product IDs '
Public Const MM_WANGLABS_WAVEIN1 = 1       '  Input audio wave on CPU board models: Exec 4010, 4030, 3450; PC 251/25c, pc 461/25s , pc 461/33c  '
Public Const MM_WANGLABS_WAVEOUT1 = 2

' MM_TANDY product IDs '
Public Const MM_TANDY_VISWAVEIN = 1
Public Const MM_TANDY_VISWAVEOUT = 2
Public Const MM_TANDY_VISBIOSSYNTH = 3
Public Const MM_TANDY_SENS_MMAWAVEIN = 4
Public Const MM_TANDY_SENS_MMAWAVEOUT = 5
Public Const MM_TANDY_SENS_MMAMIDIIN = 6
Public Const MM_TANDY_SENS_MMAMIDIOUT = 7
Public Const MM_TANDY_SENS_VISWAVEOUT = 8
Public Const MM_TANDY_PSSJWAVEIN = 9
Public Const MM_TANDY_PSSJWAVEOUT = 10

' MM_ANTEX product IDs '
Public Const MM_ANTEX_SX12_WAVEIN = 1
Public Const MM_ANTEX_SX12_WAVEOUT = 2
Public Const MM_ANTEX_SX15_WAVEIN = 3
Public Const MM_ANTEX_SX15_WAVEOUT = 4
Public Const MM_ANTEX_VP625_WAVEIN = 5
Public Const MM_ANTEX_VP625_WAVEOUT = 6
Public Const MM_ANTEX_AUDIOPORT22_WAVEIN = 7
Public Const MM_ANTEX_AUDIOPORT22_WAVEOUT = 8
Public Const MM_ANTEX_AUDIOPORT22_FEEDTHRU = 9

' MM_INTEL product IDs '
Public Const MM_INTELOPD_WAVEIN = 1       '  HID2 WaveAudio Driver  '
Public Const MM_INTELOPD_WAVEOUT = 101     '  HID2  '
Public Const MM_INTELOPD_AUX = 401     '  HID2 for mixing  '
Public Const MM_INTEL_NSPMODEMLINEIN = 501
Public Const MM_INTEL_NSPMODEMLINEOUT = 502

' MM_VAL product IDs '
Public Const MM_VAL_MICROKEY_AP_WAVEIN = 1
Public Const MM_VAL_MICROKEY_AP_WAVEOUT = 2

' MM_INTERACTIVE product IDs '
Public Const MM_INTERACTIVE_WAVEIN = &H45
Public Const MM_INTERACTIVE_WAVEOUT = &H45

' MM_YAMAHA product IDs '
Public Const MM_YAMAHA_GSS_SYNTH = &H1
Public Const MM_YAMAHA_GSS_WAVEOUT = &H2
Public Const MM_YAMAHA_GSS_WAVEIN = &H3
Public Const MM_YAMAHA_GSS_MIDIOUT = &H4
Public Const MM_YAMAHA_GSS_MIDIIN = &H5
Public Const MM_YAMAHA_GSS_AUX = &H6
Public Const MM_YAMAHA_SERIAL_MIDIOUT = &H7
Public Const MM_YAMAHA_SERIAL_MIDIIN = &H8
Public Const MM_YAMAHA_OPL3SA_WAVEOUT = &H10
Public Const MM_YAMAHA_OPL3SA_WAVEIN = &H11
Public Const MM_YAMAHA_OPL3SA_FMSYNTH = &H12
Public Const MM_YAMAHA_OPL3SA_YSYNTH = &H13
Public Const MM_YAMAHA_OPL3SA_MIDIOUT = &H14
Public Const MM_YAMAHA_OPL3SA_MIDIIN = &H15
Public Const MM_YAMAHA_OPL3SA_MIXER = &H17
Public Const MM_YAMAHA_OPL3SA_JOYSTICK = &H18
Public Const MM_YAMAHA_YMF724LEG_MIDIOUT = &H19
Public Const MM_YAMAHA_YMF724LEG_MIDIIN = &H1A
Public Const MM_YAMAHA_YMF724_WAVEOUT = &H1B
Public Const MM_YAMAHA_YMF724_WAVEIN = &H1C
Public Const MM_YAMAHA_YMF724_MIDIOUT = &H1D
Public Const MM_YAMAHA_YMF724_AUX = &H1E
Public Const MM_YAMAHA_YMF724_MIXER = &H1F
Public Const MM_YAMAHA_YMF724LEG_FMSYNTH = &H20
Public Const MM_YAMAHA_YMF724LEG_MIXER = &H21
Public Const MM_YAMAHA_SXG_MIDIOUT = &H22
Public Const MM_YAMAHA_SXG_WAVEOUT = &H23
Public Const MM_YAMAHA_SXG_MIXER = &H24
Public Const MM_YAMAHA_ACXG_WAVEIN = &H25
Public Const MM_YAMAHA_ACXG_WAVEOUT = &H26
Public Const MM_YAMAHA_ACXG_MIDIOUT = &H27
Public Const MM_YAMAHA_ACXG_MIXER = &H28
Public Const MM_YAMAHA_ACXG_AUX = &H29

' MM_EVEREX product IDs '
Public Const MM_EVEREX_CARRIER = 1

' MM_ECHO product IDs '
Public Const MM_ECHO_SYNTH = 1
Public Const MM_ECHO_WAVEOUT = 2
Public Const MM_ECHO_WAVEIN = 3
Public Const MM_ECHO_MIDIOUT = 4
Public Const MM_ECHO_MIDIIN = 5
Public Const MM_ECHO_AUX = 6

' MM_SIERRA product IDs '
Public Const MM_SIERRA_ARIA_MIDIOUT = &H14
Public Const MM_SIERRA_ARIA_MIDIIN = &H15
Public Const MM_SIERRA_ARIA_SYNTH = &H16
Public Const MM_SIERRA_ARIA_WAVEOUT = &H17
Public Const MM_SIERRA_ARIA_WAVEIN = &H18
Public Const MM_SIERRA_ARIA_AUX = &H19
Public Const MM_SIERRA_ARIA_AUX2 = &H20
Public Const MM_SIERRA_QUARTET_WAVEIN = &H50
Public Const MM_SIERRA_QUARTET_WAVEOUT = &H51
Public Const MM_SIERRA_QUARTET_MIDIIN = &H52
Public Const MM_SIERRA_QUARTET_MIDIOUT = &H53
Public Const MM_SIERRA_QUARTET_SYNTH = &H54
Public Const MM_SIERRA_QUARTET_AUX_CD = &H55
Public Const MM_SIERRA_QUARTET_AUX_LINE = &H56
Public Const MM_SIERRA_QUARTET_AUX_MODEM = &H57
Public Const MM_SIERRA_QUARTET_MIXER = &H58

' MM_CAT product IDs '
Public Const MM_CAT_WAVEOUT = 1

' MM_DSP_GROUP product IDs '
Public Const MM_DSP_GROUP_TRUESPEECH = 1

' MM_MELABS product IDs '
Public Const MM_MELABS_MIDI2GO = 1

' MM_ESS product IDs '
Public Const MM_ESS_AMWAVEOUT = &H1
Public Const MM_ESS_AMWAVEIN = &H2
Public Const MM_ESS_AMAUX = &H3
Public Const MM_ESS_AMSYNTH = &H4
Public Const MM_ESS_AMMIDIOUT = &H5
Public Const MM_ESS_AMMIDIIN = &H6
Public Const MM_ESS_MIXER = &H7
Public Const MM_ESS_AUX_CD = &H8
Public Const MM_ESS_MPU401_MIDIOUT = &H9
Public Const MM_ESS_MPU401_MIDIIN = &HA
Public Const MM_ESS_ES488_WAVEOUT = &H10
Public Const MM_ESS_ES488_WAVEIN = &H11
Public Const MM_ESS_ES488_MIXER = &H12
Public Const MM_ESS_ES688_WAVEOUT = &H13
Public Const MM_ESS_ES688_WAVEIN = &H14
Public Const MM_ESS_ES688_MIXER = &H15
Public Const MM_ESS_ES1488_WAVEOUT = &H16
Public Const MM_ESS_ES1488_WAVEIN = &H17
Public Const MM_ESS_ES1488_MIXER = &H18
Public Const MM_ESS_ES1688_WAVEOUT = &H19
Public Const MM_ESS_ES1688_WAVEIN = &H1A
Public Const MM_ESS_ES1688_MIXER = &H1B
Public Const MM_ESS_ES1788_WAVEOUT = &H1C
Public Const MM_ESS_ES1788_WAVEIN = &H1D
Public Const MM_ESS_ES1788_MIXER = &H1E
Public Const MM_ESS_ES1888_WAVEOUT = &H1F
Public Const MM_ESS_ES1888_WAVEIN = &H20
Public Const MM_ESS_ES1888_MIXER = &H21
Public Const MM_ESS_ES1868_WAVEOUT = &H22
Public Const MM_ESS_ES1868_WAVEIN = &H23
Public Const MM_ESS_ES1868_MIXER = &H24
Public Const MM_ESS_ES1878_WAVEOUT = &H25
Public Const MM_ESS_ES1878_WAVEIN = &H26
Public Const MM_ESS_ES1878_MIXER = &H27

' MM_CANOPUS product IDs '
Public Const MM_CANOPUS_ACM_DVREX = 1

' MM_EPSON product IDs '
Public Const MM_EPS_FMSND = 1

' MM_TRUEVISION product IDs '
Public Const MM_TRUEVISION_WAVEIN1 = 1
Public Const MM_TRUEVISION_WAVEOUT1 = 2

' MM_AZTECH product IDs '
Public Const MM_AZTECH_MIDIOUT = 3
Public Const MM_AZTECH_MIDIIN = 4
Public Const MM_AZTECH_WAVEIN = 17
Public Const MM_AZTECH_WAVEOUT = 18
Public Const MM_AZTECH_FMSYNTH = 20
Public Const MM_AZTECH_MIXER = 21
Public Const MM_AZTECH_PRO16_WAVEIN = 33
Public Const MM_AZTECH_PRO16_WAVEOUT = 34
Public Const MM_AZTECH_PRO16_FMSYNTH = 38
Public Const MM_AZTECH_DSP16_WAVEIN = 65
Public Const MM_AZTECH_DSP16_WAVEOUT = 66
Public Const MM_AZTECH_DSP16_FMSYNTH = 68
Public Const MM_AZTECH_DSP16_WAVESYNTH = 70
Public Const MM_AZTECH_NOVA16_WAVEIN = 71
Public Const MM_AZTECH_NOVA16_WAVEOUT = 72
Public Const MM_AZTECH_NOVA16_MIXER = 73
Public Const MM_AZTECH_WASH16_WAVEIN = 74
Public Const MM_AZTECH_WASH16_WAVEOUT = 75
Public Const MM_AZTECH_WASH16_MIXER = 76
Public Const MM_AZTECH_AUX_CD = 401
Public Const MM_AZTECH_AUX_LINE = 402
Public Const MM_AZTECH_AUX_MIC = 403
Public Const MM_AZTECH_AUX = 404

' MM_VIDEOLOGIC product IDs '
Public Const MM_VIDEOLOGIC_MSWAVEIN = 1
Public Const MM_VIDEOLOGIC_MSWAVEOUT = 2

' MM_KORG product IDs '
Public Const MM_KORG_PCIF_MIDIOUT = 1
Public Const MM_KORG_PCIF_MIDIIN = 2
Public Const MM_KORG_1212IO_MSWAVEIN = 3
Public Const MM_KORG_1212IO_MSWAVEOUT = 4

' MM_APT product IDs '
Public Const MM_APT_ACE100CD = 1

' MM_ICS product IDs '
Public Const MM_ICS_WAVEDECK_WAVEOUT = 1                  '  MS WSS compatible card and driver  '
Public Const MM_ICS_WAVEDECK_WAVEIN = 2
Public Const MM_ICS_WAVEDECK_MIXER = 3
Public Const MM_ICS_WAVEDECK_AUX = 4
Public Const MM_ICS_WAVEDECK_SYNTH = 5
Public Const MM_ICS_WAVEDEC_SB_WAVEOUT = 6
Public Const MM_ICS_WAVEDEC_SB_WAVEIN = 7
Public Const MM_ICS_WAVEDEC_SB_FM_MIDIOUT = 8
Public Const MM_ICS_WAVEDEC_SB_MPU401_MIDIOUT = 9
Public Const MM_ICS_WAVEDEC_SB_MPU401_MIDIIN = 10
Public Const MM_ICS_WAVEDEC_SB_MIXER = 11
Public Const MM_ICS_WAVEDEC_SB_AUX = 12
Public Const MM_ICS_2115_LITE_MIDIOUT = 13
Public Const MM_ICS_2120_LITE_MIDIOUT = 14

' MM_ITERATEDSYS product IDs '
Public Const MM_ITERATEDSYS_FUFCODEC = 1

' MM_METHEUS product IDs '
Public Const MM_METHEUS_ZIPPER = 1

' MM_WINNOV product IDs '
Public Const MM_WINNOV_CAVIAR_WAVEIN = 1
Public Const MM_WINNOV_CAVIAR_WAVEOUT = 2
Public Const MM_WINNOV_CAVIAR_VIDC = 3
Public Const MM_WINNOV_CAVIAR_CHAMPAGNE = 4               '  Fourcc is CHAM  '
Public Const MM_WINNOV_CAVIAR_YUV8 = 5                    '  Fourcc is YUV8  '

' MM_NCR product IDs '
Public Const MM_NCR_BA_WAVEIN = 1
Public Const MM_NCR_BA_WAVEOUT = 2
Public Const MM_NCR_BA_SYNTH = 3
Public Const MM_NCR_BA_AUX = 4
Public Const MM_NCR_BA_MIXER = 5

' MM_AST product IDs '
Public Const MM_AST_MODEMWAVE_WAVEIN = 13
Public Const MM_AST_MODEMWAVE_WAVEOUT = 14

' MM_WILLOWPOND product IDs '
Public Const MM_WILLOWPOND_FMSYNTH_STEREO = 20
Public Const MM_WILLOWPOND_MPU401 = 21
Public Const MM_WILLOWPOND_SNDPORT_WAVEIN = 100
Public Const MM_WILLOWPOND_SNDPORT_WAVEOUT = 101
Public Const MM_WILLOWPOND_SNDPORT_MIXER = 102
Public Const MM_WILLOWPOND_SNDPORT_AUX = 103
Public Const MM_WILLOWPOND_PH_WAVEIN = 104
Public Const MM_WILLOWPOND_PH_WAVEOUT = 105
Public Const MM_WILLOWPOND_PH_MIXER = 106
Public Const MM_WILLOWPOND_PH_AUX = 107
Public Const MM_WILLOPOND_SNDCOMM_WAVEIN = 108
Public Const MM_WILLOWPOND_SNDCOMM_WAVEOUT = 109
Public Const MM_WILLOWPOND_SNDCOMM_MIXER = 110
Public Const MM_WILLOWPOND_SNDCOMM_AUX = 111
Public Const MM_WILLOWPOND_GENERIC_WAVEIN = 112
Public Const MM_WILLOWPOND_GENERIC_WAVEOUT = 113
Public Const MM_WILLOWPOND_GENERIC_MIXER = 114
Public Const MM_WILLOWPOND_GENERIC_AUX = 115

' MM_VITEC product IDs '
Public Const MM_VITEC_VMAKER = 1
Public Const MM_VITEC_VMPRO = 2

' MM_MOSCOM product IDs '
Public Const MM_MOSCOM_VPC2400_IN = 1                     '  Four Port Voice Processing / Voice Recognition Board  '
Public Const MM_MOSCOM_VPC2400_OUT = 2                    '  VPC2400 '

' MM_SILICONSOFT product IDs '
Public Const MM_SILICONSOFT_SC1_WAVEIN = 1                '  Waveform in , high sample rate  '
Public Const MM_SILICONSOFT_SC1_WAVEOUT = 2               '  Waveform out , high sample rate  '
Public Const MM_SILICONSOFT_SC2_WAVEIN = 3                '  Waveform in 2 channels, high sample rate  '
Public Const MM_SILICONSOFT_SC2_WAVEOUT = 4               '  Waveform out 2 channels, high sample rate  '
Public Const MM_SILICONSOFT_SOUNDJR2_WAVEOUT = 5          '  Waveform out, self powered, efficient  '
Public Const MM_SILICONSOFT_SOUNDJR2PR_WAVEIN = 6         '  Waveform in, self powered, efficient  '
Public Const MM_SILICONSOFT_SOUNDJR2PR_WAVEOUT = 7        '  Waveform out 2 channels, self powered, efficient  '
Public Const MM_SILICONSOFT_SOUNDJR3_WAVEOUT = 8          '  Waveform in 2 channels, self powered, efficient  '

' MM_TERRATEC product IDs '
Public Const MM_TTEWS_WAVEIN = 1
Public Const MM_TTEWS_WAVEOUT = 2
Public Const MM_TTEWS_MIDIIN = 3
Public Const MM_TTEWS_MIDIOUT = 4
Public Const MM_TTEWS_MIDISYNTH = 5
Public Const MM_TTEWS_MIDIMONITOR = 6
Public Const MM_TTEWS_VMIDIIN = 7
Public Const MM_TTEWS_VMIDIOUT = 8
Public Const MM_TTEWS_AUX = 9
Public Const MM_TTEWS_MIXER = 10

' MM_MEDIASONIC product IDs '
Public Const MM_MEDIASONIC_ACM_G723 = 1
Public Const MM_MEDIASONIC_ICOM = 2
Public Const MM_ICOM_WAVEIN = 3
Public Const MM_ICOM_WAVEOUT = 4
Public Const MM_ICOM_MIXER = 5
Public Const MM_ICOM_AUX = 6
Public Const MM_ICOM_LINE = 7

'  MM_SANYO product IDs '
Public Const MM_SANYO_ACM_LD_ADPCM = 1

' MM_AHEAD product IDs '
Public Const MM_AHEAD_MULTISOUND = 1
Public Const MM_AHEAD_SOUNDBLASTER = 2
Public Const MM_AHEAD_PROAUDIO = 3
Public Const MM_AHEAD_GENERIC = 4

' MM_OLIVETTI product IDs '
Public Const MM_OLIVETTI_WAVEIN = 1
Public Const MM_OLIVETTI_WAVEOUT = 2
Public Const MM_OLIVETTI_MIXER = 3
Public Const MM_OLIVETTI_AUX = 4
Public Const MM_OLIVETTI_MIDIIN = 5
Public Const MM_OLIVETTI_MIDIOUT = 6
Public Const MM_OLIVETTI_SYNTH = 7
Public Const MM_OLIVETTI_JOYSTICK = 8
Public Const MM_OLIVETTI_ACM_GSM = 9
Public Const MM_OLIVETTI_ACM_ADPCM = 10
Public Const MM_OLIVETTI_ACM_CELP = 11
Public Const MM_OLIVETTI_ACM_SBC = 12
Public Const MM_OLIVETTI_ACM_OPR = 13

' MM_IOMAGIC product IDs '
Public Const MM_IOMAGIC_TEMPO_WAVEOUT = 1
Public Const MM_IOMAGIC_TEMPO_WAVEIN = 2
Public Const MM_IOMAGIC_TEMPO_SYNTH = 3
Public Const MM_IOMAGIC_TEMPO_MIDIOUT = 4
Public Const MM_IOMAGIC_TEMPO_MXDOUT = 5
Public Const MM_IOMAGIC_TEMPO_AUXOUT = 6

' MM_MATSUSHITA product IDs '
Public Const MM_MATSUSHITA_WAVEIN = 1
Public Const MM_MATSUSHITA_WAVEOUT = 2
Public Const MM_MATSUSHITA_FMSYNTH_STEREO = 3
Public Const MM_MATSUSHITA_MIXER = 4
Public Const MM_MATSUSHITA_AUX = 5

' MM_NEWMEDIA product IDs '
Public Const MM_NEWMEDIA_WAVJAMMER = 1                    '  WSS Compatible sound card.  '

' MM_LYRRUS product IDs '
Public Const MM_LYRRUS_BRIDGE_GUITAR = 1

' MM_OPTI product IDs '
Public Const MM_OPTI_M16_FMSYNTH_STEREO = &H1
Public Const MM_OPTI_M16_MIDIIN = &H2
Public Const MM_OPTI_M16_MIDIOUT = &H3
Public Const MM_OPTI_M16_WAVEIN = &H4
Public Const MM_OPTI_M16_WAVEOUT = &H5
Public Const MM_OPTI_M16_MIXER = &H6
Public Const MM_OPTI_M16_AUX = &H7
Public Const MM_OPTI_P16_FMSYNTH_STEREO = &H10
Public Const MM_OPTI_P16_MIDIIN = &H11
Public Const MM_OPTI_P16_MIDIOUT = &H12
Public Const MM_OPTI_P16_WAVEIN = &H13
Public Const MM_OPTI_P16_WAVEOUT = &H14
Public Const MM_OPTI_P16_MIXER = &H15
Public Const MM_OPTI_P16_AUX = &H16
Public Const MM_OPTI_M32_WAVEIN = &H20
Public Const MM_OPTI_M32_WAVEOUT = &H21
Public Const MM_OPTI_M32_MIDIIN = &H22
Public Const MM_OPTI_M32_MIDIOUT = &H23
Public Const MM_OPTI_M32_SYNTH_STEREO = &H24
Public Const MM_OPTI_M32_MIXER = &H25
Public Const MM_OPTI_M32_AUX = &H26

' MM_COMPAQ product IDs '
Public Const MM_COMPAQ_BB_WAVEIN = 1
Public Const MM_COMPAQ_BB_WAVEOUT = 2
Public Const MM_COMPAQ_BB_WAVEAUX = 3

' MM_MPTUS product IDs '
Public Const MM_MPTUS_SPWAVEOUT = 1                       ' Sound Pallette '

' MM_LERNOUT_AND_HAUSPIE product IDs '
Public Const MM_LERNOUT_ANDHAUSPIE_LHCODECACM = 1

' MM_DIGITAL product IDs '
Public Const MM_DIGITAL_AV320_WAVEIN = 1                  ' Digital Audio Video Compression Board '
Public Const MM_DIGITAL_AV320_WAVEOUT = 2                 ' Digital Audio Video Compression Board '
Public Const MM_DIGITAL_ACM_G723 = 3
Public Const MM_DIGITAL_ICM_H263 = 4
Public Const MM_DIGITAL_ICM_H261 = 5

' MM_MOTU product IDs '
Public Const MM_MOTU_MTP_MIDIOUT_ALL = 100
Public Const MM_MOTU_MTP_MIDIIN_1 = 101
Public Const MM_MOTU_MTP_MIDIOUT_1 = 101
Public Const MM_MOTU_MTP_MIDIIN_2 = 102
Public Const MM_MOTU_MTP_MIDIOUT_2 = 102
Public Const MM_MOTU_MTP_MIDIIN_3 = 103
Public Const MM_MOTU_MTP_MIDIOUT_3 = 103
Public Const MM_MOTU_MTP_MIDIIN_4 = 104
Public Const MM_MOTU_MTP_MIDIOUT_4 = 104
Public Const MM_MOTU_MTP_MIDIIN_5 = 105
Public Const MM_MOTU_MTP_MIDIOUT_5 = 105
Public Const MM_MOTU_MTP_MIDIIN_6 = 106
Public Const MM_MOTU_MTP_MIDIOUT_6 = 106
Public Const MM_MOTU_MTP_MIDIIN_7 = 107
Public Const MM_MOTU_MTP_MIDIOUT_7 = 107
Public Const MM_MOTU_MTP_MIDIIN_8 = 108
Public Const MM_MOTU_MTP_MIDIOUT_8 = 108

Public Const MM_MOTU_MTPII_MIDIOUT_ALL = 200
Public Const MM_MOTU_MTPII_MIDIIN_SYNC = 200
Public Const MM_MOTU_MTPII_MIDIIN_1 = 201
Public Const MM_MOTU_MTPII_MIDIOUT_1 = 201
Public Const MM_MOTU_MTPII_MIDIIN_2 = 202
Public Const MM_MOTU_MTPII_MIDIOUT_2 = 202
Public Const MM_MOTU_MTPII_MIDIIN_3 = 203
Public Const MM_MOTU_MTPII_MIDIOUT_3 = 203
Public Const MM_MOTU_MTPII_MIDIIN_4 = 204
Public Const MM_MOTU_MTPII_MIDIOUT_4 = 204
Public Const MM_MOTU_MTPII_MIDIIN_5 = 205
Public Const MM_MOTU_MTPII_MIDIOUT_5 = 205
Public Const MM_MOTU_MTPII_MIDIIN_6 = 206
Public Const MM_MOTU_MTPII_MIDIOUT_6 = 206
Public Const MM_MOTU_MTPII_MIDIIN_7 = 207
Public Const MM_MOTU_MTPII_MIDIOUT_7 = 207
Public Const MM_MOTU_MTPII_MIDIIN_8 = 208
Public Const MM_MOTU_MTPII_MIDIOUT_8 = 208
Public Const MM_MOTU_MTPII_NET_MIDIIN_1 = 209
Public Const MM_MOTU_MTPII_NET_MIDIOUT_1 = 209
Public Const MM_MOTU_MTPII_NET_MIDIIN_2 = 210
Public Const MM_MOTU_MTPII_NET_MIDIOUT_2 = 210
Public Const MM_MOTU_MTPII_NET_MIDIIN_3 = 211
Public Const MM_MOTU_MTPII_NET_MIDIOUT_3 = 211
Public Const MM_MOTU_MTPII_NET_MIDIIN_4 = 212
Public Const MM_MOTU_MTPII_NET_MIDIOUT_4 = 212
Public Const MM_MOTU_MTPII_NET_MIDIIN_5 = 213
Public Const MM_MOTU_MTPII_NET_MIDIOUT_5 = 213
Public Const MM_MOTU_MTPII_NET_MIDIIN_6 = 214
Public Const MM_MOTU_MTPII_NET_MIDIOUT_6 = 214
Public Const MM_MOTU_MTPII_NET_MIDIIN_7 = 215
Public Const MM_MOTU_MTPII_NET_MIDIOUT_7 = 215
Public Const MM_MOTU_MTPII_NET_MIDIIN_8 = 216
Public Const MM_MOTU_MTPII_NET_MIDIOUT_8 = 216

Public Const MM_MOTU_MXP_MIDIIN_MIDIOUT_ALL = 300
Public Const MM_MOTU_MXP_MIDIIN_SYNC = 300
Public Const MM_MOTU_MXP_MIDIIN_MIDIIN_1 = 301
Public Const MM_MOTU_MXP_MIDIIN_MIDIOUT_1 = 301
Public Const MM_MOTU_MXP_MIDIIN_MIDIIN_2 = 302
Public Const MM_MOTU_MXP_MIDIIN_MIDIOUT_2 = 302
Public Const MM_MOTU_MXP_MIDIIN_MIDIIN_3 = 303
Public Const MM_MOTU_MXP_MIDIIN_MIDIOUT_3 = 303
Public Const MM_MOTU_MXP_MIDIIN_MIDIIN_4 = 304
Public Const MM_MOTU_MXP_MIDIIN_MIDIOUT_4 = 304
Public Const MM_MOTU_MXP_MIDIIN_MIDIIN_5 = 305
Public Const MM_MOTU_MXP_MIDIIN_MIDIOUT_5 = 305
Public Const MM_MOTU_MXP_MIDIIN_MIDIIN_6 = 306
Public Const MM_MOTU_MXP_MIDIIN_MIDIOUT_6 = 306

Public Const MM_MOTU_MXPMPU_MIDIOUT_ALL = 400
Public Const MM_MOTU_MXPMPU_MIDIIN_SYNC = 400
Public Const MM_MOTU_MXPMPU_MIDIIN_1 = 401
Public Const MM_MOTU_MXPMPU_MIDIOUT_1 = 401
Public Const MM_MOTU_MXPMPU_MIDIIN_2 = 402
Public Const MM_MOTU_MXPMPU_MIDIOUT_2 = 402
Public Const MM_MOTU_MXPMPU_MIDIIN_3 = 403
Public Const MM_MOTU_MXPMPU_MIDIOUT_3 = 403
Public Const MM_MOTU_MXPMPU_MIDIIN_4 = 404
Public Const MM_MOTU_MXPMPU_MIDIOUT_4 = 404
Public Const MM_MOTU_MXPMPU_MIDIIN_5 = 405
Public Const MM_MOTU_MXPMPU_MIDIOUT_5 = 405
Public Const MM_MOTU_MXPMPU_MIDIIN_6 = 406
Public Const MM_MOTU_MXPMPU_MIDIOUT_6 = 406

Public Const MM_MOTU_MXN_MIDIOUT_ALL = 500
Public Const MM_MOTU_MXN_MIDIIN_SYNC = 500
Public Const MM_MOTU_MXN_MIDIIN_1 = 501
Public Const MM_MOTU_MXN_MIDIOUT_1 = 501
Public Const MM_MOTU_MXN_MIDIIN_2 = 502
Public Const MM_MOTU_MXN_MIDIOUT_2 = 502
Public Const MM_MOTU_MXN_MIDIIN_3 = 503
Public Const MM_MOTU_MXN_MIDIOUT_3 = 503
Public Const MM_MOTU_MXN_MIDIIN_4 = 504
Public Const MM_MOTU_MXN_MIDIOUT_4 = 504

Public Const MM_MOTU_FLYER_MIDI_IN_SYNC = 600
Public Const MM_MOTU_FLYER_MIDI_IN_A = 601
Public Const MM_MOTU_FLYER_MIDI_OUT_A = 601
Public Const MM_MOTU_FLYER_MIDI_IN_B = 602
Public Const MM_MOTU_FLYER_MIDI_OUT_B = 602

Public Const MM_MOTU_PKX_MIDI_IN_SYNC = 700
Public Const MM_MOTU_PKX_MIDI_IN_A = 701
Public Const MM_MOTU_PKX_MIDI_OUT_A = 701
Public Const MM_MOTU_PKX_MIDI_IN_B = 702
Public Const MM_MOTU_PKX_MIDI_OUT_B = 702

Public Const MM_MOTU_DTX_MIDI_IN_SYNC = 800
Public Const MM_MOTU_DTX_MIDI_IN_A = 801
Public Const MM_MOTU_DTX_MIDI_OUT_A = 801
Public Const MM_MOTU_DTX_MIDI_IN_B = 802
Public Const MM_MOTU_DTX_MIDI_OUT_B = 802

Public Const MM_MOTU_MTPAV_MIDIOUT_ALL = 900
Public Const MM_MOTU_MTPAV_MIDIIN_SYNC = 900
Public Const MM_MOTU_MTPAV_MIDIIN_1 = 901
Public Const MM_MOTU_MTPAV_MIDIOUT_1 = 901
Public Const MM_MOTU_MTPAV_MIDIIN_2 = 902
Public Const MM_MOTU_MTPAV_MIDIOUT_2 = 902
Public Const MM_MOTU_MTPAV_MIDIIN_3 = 903
Public Const MM_MOTU_MTPAV_MIDIOUT_3 = 903
Public Const MM_MOTU_MTPAV_MIDIIN_4 = 904
Public Const MM_MOTU_MTPAV_MIDIOUT_4 = 904
Public Const MM_MOTU_MTPAV_MIDIIN_5 = 905
Public Const MM_MOTU_MTPAV_MIDIOUT_5 = 905
Public Const MM_MOTU_MTPAV_MIDIIN_6 = 906
Public Const MM_MOTU_MTPAV_MIDIOUT_6 = 906
Public Const MM_MOTU_MTPAV_MIDIIN_7 = 907
Public Const MM_MOTU_MTPAV_MIDIOUT_7 = 907
Public Const MM_MOTU_MTPAV_MIDIIN_8 = 908
Public Const MM_MOTU_MTPAV_MIDIOUT_8 = 908
Public Const MM_MOTU_MTPAV_NET_MIDIIN_1 = 909
Public Const MM_MOTU_MTPAV_NET_MIDIOUT_1 = 909
Public Const MM_MOTU_MTPAV_NET_MIDIIN_2 = 910
Public Const MM_MOTU_MTPAV_NET_MIDIOUT_2 = 910
Public Const MM_MOTU_MTPAV_NET_MIDIIN_3 = 911
Public Const MM_MOTU_MTPAV_NET_MIDIOUT_3 = 911
Public Const MM_MOTU_MTPAV_NET_MIDIIN_4 = 912
Public Const MM_MOTU_MTPAV_NET_MIDIOUT_4 = 912
Public Const MM_MOTU_MTPAV_NET_MIDIIN_5 = 913
Public Const MM_MOTU_MTPAV_NET_MIDIOUT_5 = 913
Public Const MM_MOTU_MTPAV_NET_MIDIIN_6 = 914
Public Const MM_MOTU_MTPAV_NET_MIDIOUT_6 = 914
Public Const MM_MOTU_MTPAV_NET_MIDIIN_7 = 915
Public Const MM_MOTU_MTPAV_NET_MIDIOUT_7 = 915
Public Const MM_MOTU_MTPAV_NET_MIDIIN_8 = 916
Public Const MM_MOTU_MTPAV_NET_MIDIOUT_8 = 916
Public Const MM_MOTU_MTPAV_MIDIIN_ADAT = 917
Public Const MM_MOTU_MTPAV_MIDIOUT_ADAT = 917
Public Const MM_MOTU_MXPXT_MIDIIN_SYNC = 1000
Public Const MM_MOTU_MXPXT_MIDIOUT_ALL = 1000
Public Const MM_MOTU_MXPXT_MIDIIN_1 = 1001
Public Const MM_MOTU_MXPXT_MIDIOUT_1 = 1001
Public Const MM_MOTU_MXPXT_MIDIOUT_2 = 1002
Public Const MM_MOTU_MXPXT_MIDIIN_2 = 1002
Public Const MM_MOTU_MXPXT_MIDIIN_3 = 1003
Public Const MM_MOTU_MXPXT_MIDIOUT_3 = 1003
Public Const MM_MOTU_MXPXT_MIDIIN_4 = 1004
Public Const MM_MOTU_MXPXT_MIDIOUT_4 = 1004
Public Const MM_MOTU_MXPXT_MIDIIN_5 = 1005
Public Const MM_MOTU_MXPXT_MIDIOUT_5 = 1005
Public Const MM_MOTU_MXPXT_MIDIOUT_6 = 1006
Public Const MM_MOTU_MXPXT_MIDIIN_6 = 1006
Public Const MM_MOTU_MXPXT_MIDIOUT_7 = 1007
Public Const MM_MOTU_MXPXT_MIDIIN_7 = 1007
Public Const MM_MOTU_MXPXT_MIDIOUT_8 = 1008
Public Const MM_MOTU_MXPXT_MIDIIN_8 = 1008

' MM_WORKBIT product IDs '
Public Const MM_WORKBIT_MIXER = 1                        ' Harmony Mixer '
Public Const MM_WORKBIT_WAVEOUT = 2                      ' Harmony Mixer '
Public Const MM_WORKBIT_WAVEIN = 3                       ' Harmony Mixer '
Public Const MM_WORKBIT_MIDIIN = 4                       ' Harmony Mixer '
Public Const MM_WORKBIT_MIDIOUT = 5                      ' Harmony Mixer '
Public Const MM_WORKBIT_FMSYNTH = 6                      ' Harmony Mixer '
Public Const MM_WORKBIT_AUX = 7                          ' Harmony Mixer '
Public Const MM_WORKBIT_JOYSTICK = 8

' MM_OSITECH product IDs '
Public Const MM_OSITECH_TRUMPCARD = 1                     ' Trumpcard '

' MM_MIRO product IDs '
Public Const MM_MIRO_MOVIEPRO = 1                         ' miroMOVIE pro '
Public Const MM_MIRO_VIDEOD1 = 2                          ' miroVIDEO D1 '
Public Const MM_MIRO_VIDEODC1TV = 3                       ' miroVIDEO DC1 tv '
Public Const MM_MIRO_VIDEOTD = 4                          ' miroVIDEO 10/20 TD '
Public Const MM_MIRO_DC30_WAVEOUT = 5
Public Const MM_MIRO_DC30_WAVEIN = 6
Public Const MM_MIRO_DC30_MIX = 7

' MM_ISOLUTION product IDs '
Public Const MM_ISOLUTION_PASCAL = 1

' MM_ROCKWELL product IDs '
Public Const MM_VOICEMIXER = 1
Public Const ROCKWELL_WA1_WAVEIN = 100
Public Const ROCKWELL_WA1_WAVEOUT = 101
Public Const ROCKWELL_WA1_SYNTH = 102
Public Const ROCKWELL_WA1_MIXER = 103
Public Const ROCKWELL_WA1_MPU401_IN = 104
Public Const ROCKWELL_WA1_MPU401_OUT = 105
Public Const ROCKWELL_WA2_WAVEIN = 200
Public Const ROCKWELL_WA2_WAVEOUT = 201
Public Const ROCKWELL_WA2_SYNTH = 202
Public Const ROCKWELL_WA2_MIXER = 203
Public Const ROCKWELL_WA2_MPU401_IN = 204
Public Const ROCKWELL_WA2_MPU401_OUT = 205

' MM_VOXWARE product IDs '
Public Const MM_VOXWARE_CODEC = 1

' MM_NORTHERN_TELECOM product IDs '
Public Const MM_NORTEL_MPXAC_WAVEIN = 1                   ' MPX Audio Card Wave Input Device '
Public Const MM_NORTEL_MPXAC_WAVEOUT = 2                  ' MPX Audio Card Wave Output Device '

' MM_ADDX product IDs '
Public Const MM_ADDX_PCTV_DIGITALMIX = 1                  ' MM_ADDX_PCTV_DIGITALMIX '
Public Const MM_ADDX_PCTV_WAVEIN = 2                      ' MM_ADDX_PCTV_WAVEIN '
Public Const MM_ADDX_PCTV_WAVEOUT = 3                     ' MM_ADDX_PCTV_WAVEOUT '
Public Const MM_ADDX_PCTV_MIXER = 4                       ' MM_ADDX_PCTV_MIXER '
Public Const MM_ADDX_PCTV_AUX_CD = 5                      ' MM_ADDX_PCTV_AUX_CD '
Public Const MM_ADDX_PCTV_AUX_LINE = 6                    ' MM_ADDX_PCTV_AUX_LINE '

' MM_WILDCAT product IDs '
Public Const MM_WILDCAT_AUTOSCOREMIDIIN = 1               ' Autoscore '

' MM_RHETOREX product IDs '
Public Const MM_RHETOREX_WAVEIN = 1
Public Const MM_RHETOREX_WAVEOUT = 2

' MM_BROOKTREE product IDs '
Public Const MM_BTV_WAVEIN = 1                            ' Brooktree PCM Wave Audio In '
Public Const MM_BTV_WAVEOUT = 2                           ' Brooktree PCM Wave Audio Out '
Public Const MM_BTV_MIDIIN = 3                            ' Brooktree MIDI In '
Public Const MM_BTV_MIDIOUT = 4                           ' Brooktree MIDI out '
Public Const MM_BTV_MIDISYNTH = 5                         ' Brooktree MIDI FM synth '
Public Const MM_BTV_AUX_LINE = 6                          ' Brooktree Line Input '
Public Const MM_BTV_AUX_MIC = 7                           ' Brooktree Microphone Input '
Public Const MM_BTV_AUX_CD = 8                            ' Brooktree CD Input '
Public Const MM_BTV_DIGITALIN = 9                         ' Brooktree PCM Wave in with subcode information '
Public Const MM_BTV_DIGITALOUT = 10                       ' Brooktree PCM Wave out with subcode information '
Public Const MM_BTV_MIDIWAVESTREAM = 11                   ' Brooktree WaveStream '
Public Const MM_BTV_MIXER = 12                            ' Brooktree WSS Mixer driver '

' MM_ENSONIQ product IDs '
Public Const MM_ENSONIQ_SOUNDSCAPE = &H10                 ' ENSONIQ Soundscape '
Public Const MM_SOUNDSCAPE_WAVEOUT = MM_ENSONIQ_SOUNDSCAPE + 1
Public Const MM_SOUNDSCAPE_WAVEOUT_AUX = MM_ENSONIQ_SOUNDSCAPE + 2
Public Const MM_SOUNDSCAPE_WAVEIN = MM_ENSONIQ_SOUNDSCAPE + 3
Public Const MM_SOUNDSCAPE_MIDIOUT = MM_ENSONIQ_SOUNDSCAPE + 4
Public Const MM_SOUNDSCAPE_MIDIIN = MM_ENSONIQ_SOUNDSCAPE + 5
Public Const MM_SOUNDSCAPE_SYNTH = MM_ENSONIQ_SOUNDSCAPE + 6
Public Const MM_SOUNDSCAPE_MIXER = MM_ENSONIQ_SOUNDSCAPE + 7
Public Const MM_SOUNDSCAPE_AUX = MM_ENSONIQ_SOUNDSCAPE + 8

' MM_NVIDIA product IDs '
Public Const MM_NVIDIA_WAVEOUT = 1
Public Const MM_NVIDIA_WAVEIN = 2
Public Const MM_NVIDIA_MIDIOUT = 3
Public Const MM_NVIDIA_MIDIIN = 4
Public Const MM_NVIDIA_GAMEPORT = 5
Public Const MM_NVIDIA_MIXER = 6
Public Const MM_NVIDIA_AUX = 7

' MM_OKSORI product IDs '
Public Const MM_OKSORI_BASE = 0                                          ' Oksori Base '
Public Const MM_OKSORI_OSR8_WAVEOUT = MM_OKSORI_BASE + 1                 ' Oksori 8bit Wave out '
Public Const MM_OKSORI_OSR8_WAVEIN = MM_OKSORI_BASE + 2                  ' Oksori 8bit Wave in '
Public Const MM_OKSORI_OSR16_WAVEOUT = MM_OKSORI_BASE + 3                ' Oksori 16 bit Wave out '
Public Const MM_OKSORI_OSR16_WAVEIN = MM_OKSORI_BASE + 4                 ' Oksori 16 bit Wave in '
Public Const MM_OKSORI_FM_OPL4 = MM_OKSORI_BASE + 5                      ' Oksori FM Synth Yamaha OPL4 '
Public Const MM_OKSORI_MIX_MASTER = MM_OKSORI_BASE + 6                   ' Oksori DSP Mixer - Master Volume '
Public Const MM_OKSORI_MIX_WAVE = MM_OKSORI_BASE + 7                     ' Oksori DSP Mixer - Wave Volume '
Public Const MM_OKSORI_MIX_FM = MM_OKSORI_BASE + 8                       ' Oksori DSP Mixer - FM Volume '
Public Const MM_OKSORI_MIX_LINE = MM_OKSORI_BASE + 9                     ' Oksori DSP Mixer - Line Volume '
Public Const MM_OKSORI_MIX_CD = MM_OKSORI_BASE + 10                      ' Oksori DSP Mixer - CD Volume '
Public Const MM_OKSORI_MIX_MIC = MM_OKSORI_BASE + 11                     ' Oksori DSP Mixer - MIC Volume '
Public Const MM_OKSORI_MIX_ECHO = MM_OKSORI_BASE + 12                    ' Oksori DSP Mixer - Echo Volume '
Public Const MM_OKSORI_MIX_AUX1 = MM_OKSORI_BASE + 13                    ' Oksori AD1848 - AUX1 Volume '
Public Const MM_OKSORI_MIX_LINE1 = MM_OKSORI_BASE + 14                   ' Oksori AD1848 - LINE1 Volume '
Public Const MM_OKSORI_EXT_MIC1 = MM_OKSORI_BASE + 15                    ' Oksori External - One Mic Connect '
Public Const MM_OKSORI_EXT_MIC2 = MM_OKSORI_BASE + 16                    ' Oksori External - Two Mic Connect '
Public Const MM_OKSORI_MIDIOUT = MM_OKSORI_BASE + 17                     ' Oksori MIDI Out Device '
Public Const MM_OKSORI_MIDIIN = MM_OKSORI_BASE + 18                      ' Oksori MIDI In Device '
Public Const MM_OKSORI_MPEG_CDVISION = MM_OKSORI_BASE + 19               ' Oksori CD-Vision MPEG Decoder '

' MM_DIACOUSTICS product IDs '
Public Const MM_DIACOUSTICS_DRUM_ACTION = 1               ' Drum Action '

' MM_KAY_ELEMETRICS product IDs '
Public Const MM_KAY_ELEMETRICS_CSL = &H4300
Public Const MM_KAY_ELEMETRICS_CSL_DAT = &H4308
Public Const MM_KAY_ELEMETRICS_CSL_4CHANNEL = &H4309

' MM_CRYSTAL product IDs '
Public Const MM_CRYSTAL_CS4232_WAVEIN = 1
Public Const MM_CRYSTAL_CS4232_WAVEOUT = 2
Public Const MM_CRYSTAL_CS4232_WAVEMIXER = 3
Public Const MM_CRYSTAL_CS4232_WAVEAUX_AUX1 = 4
Public Const MM_CRYSTAL_CS4232_WAVEAUX_AUX2 = 5
Public Const MM_CRYSTAL_CS4232_WAVEAUX_LINE = 6
Public Const MM_CRYSTAL_CS4232_WAVEAUX_MONO = 7
Public Const MM_CRYSTAL_CS4232_WAVEAUX_MASTER = 8
Public Const MM_CRYSTAL_CS4232_MIDIIN = 9
Public Const MM_CRYSTAL_CS4232_MIDIOUT = 10
Public Const MM_CRYSTAL_CS4232_INPUTGAIN_AUX1 = 13
Public Const MM_CRYSTAL_CS4232_INPUTGAIN_LOOP = 14
Public Const MM_CRYSTAL_SOUND_FUSION_WAVEIN = 21
Public Const MM_CRYSTAL_SOUND_FUSION_WAVEOUT = 22
Public Const MM_CRYSTAL_SOUND_FUSION_MIXER = 23
Public Const MM_CRYSTAL_SOUND_FUSION_MIDIIN = 24
Public Const MM_CRYSTAL_SOUND_FUSION_MIDIOUT = 25
Public Const MM_CRYSTAL_SOUND_FUSION_JOYSTICK = 26

' MM_QUARTERDECK product IDs '
Public Const MM_QUARTERDECK_LHWAVEIN = 0                 ' Quarterdeck L&H Codec Wave In '
Public Const MM_QUARTERDECK_LHWAVEOUT = 1                ' Quarterdeck L&H Codec Wave Out '

' MM_TDK product IDs '
Public Const MM_TDK_MW_MIDI_SYNTH = 1
Public Const MM_TDK_MW_MIDI_IN = 2
Public Const MM_TDK_MW_MIDI_OUT = 3
Public Const MM_TDK_MW_WAVE_IN = 4
Public Const MM_TDK_MW_WAVE_OUT = 5
Public Const MM_TDK_MW_AUX = 6
Public Const MM_TDK_MW_MIXER = 10
Public Const MM_TDK_MW_AUX_MASTER = 100
Public Const MM_TDK_MW_AUX_BASS = 101
Public Const MM_TDK_MW_AUX_TREBLE = 102
Public Const MM_TDK_MW_AUX_MIDI_VOL = 103
Public Const MM_TDK_MW_AUX_WAVE_VOL = 104
Public Const MM_TDK_MW_AUX_WAVE_RVB = 105
Public Const MM_TDK_MW_AUX_WAVE_CHR = 106
Public Const MM_TDK_MW_AUX_VOL = 107
Public Const MM_TDK_MW_AUX_RVB = 108
Public Const MM_TDK_MW_AUX_CHR = 109

' MM_DIGITAL_AUDIO_LABS product IDs '
Public Const MM_DIGITAL_AUDIO_LABS_TC = &H1
Public Const MM_DIGITAL_AUDIO_LABS_DOC = &H2
Public Const MM_DIGITAL_AUDIO_LABS_V8 = &H10
Public Const MM_DIGITAL_AUDIO_LABS_CPRO = &H11
Public Const MM_DIGITAL_AUDIO_LABS_VP = &H12
Public Const MM_DIGITAL_AUDIO_LABS_CDLX = &H13
Public Const MM_DIGITAL_AUDIO_LABS_CTDIF = &H14

' MM_SEERSYS product IDs '
Public Const MM_SEERSYS_SEERSYNTH = 1
Public Const MM_SEERSYS_SEERWAVE = 2
Public Const MM_SEERSYS_SEERMIX = 3
Public Const MM_SEERSYS_WAVESYNTH = 4
Public Const MM_SEERSYS_WAVESYNTH_WG = 5
Public Const MM_SEERSYS_REALITY = 6

' MM_OSPREY product IDs '
Public Const MM_OSPREY_1000WAVEIN = 1
Public Const MM_OSPREY_1000WAVEOUT = 2

' MM_SOUNDESIGNS product IDs '
Public Const MM_SOUNDESIGNS_WAVEIN = 1
Public Const MM_SOUNDESIGNS_WAVEOUT = 2

' MM_SPECTRUM_SIGNAL_PROCESSING product IDs '
Public Const MM_SSP_SNDFESWAVEIN = 1                      ' Sound Festa Wave In Device '
Public Const MM_SSP_SNDFESWAVEOUT = 2                     ' Sound Festa Wave Out Device '
Public Const MM_SSP_SNDFESMIDIIN = 3                      ' Sound Festa MIDI In Device '
Public Const MM_SSP_SNDFESMIDIOUT = 4                     ' Sound Festa MIDI Out Device '
Public Const MM_SSP_SNDFESSYNTH = 5                       ' Sound Festa MIDI Synth Device '
Public Const MM_SSP_SNDFESMIX = 6                         ' Sound Festa Mixer Device '
Public Const MM_SSP_SNDFESAUX = 7                         ' Sound Festa Auxilliary Device '

' MM_ECS product IDs '
Public Const MM_ECS_AADF_MIDI_IN = 10
Public Const MM_ECS_AADF_MIDI_OUT = 11
Public Const MM_ECS_AADF_WAVE2MIDI_IN = 12

' MM_AMD product IDs '
Public Const MM_AMD_INTERWAVE_WAVEIN = 1
Public Const MM_AMD_INTERWAVE_WAVEOUT = 2
Public Const MM_AMD_INTERWAVE_SYNTH = 3
Public Const MM_AMD_INTERWAVE_MIXER1 = 4
Public Const MM_AMD_INTERWAVE_MIXER2 = 5
Public Const MM_AMD_INTERWAVE_JOYSTICK = 6
Public Const MM_AMD_INTERWAVE_EX_CD = 7
Public Const MM_AMD_INTERWAVE_MIDIIN = 8
Public Const MM_AMD_INTERWAVE_MIDIOUT = 9
Public Const MM_AMD_INTERWAVE_AUX1 = 10
Public Const MM_AMD_INTERWAVE_AUX2 = 11
Public Const MM_AMD_INTERWAVE_AUX_MIC = 12
Public Const MM_AMD_INTERWAVE_AUX_CD = 13
Public Const MM_AMD_INTERWAVE_MONO_IN = 14
Public Const MM_AMD_INTERWAVE_MONO_OUT = 15
Public Const MM_AMD_INTERWAVE_EX_TELEPHONY = 16
Public Const MM_AMD_INTERWAVE_WAVEOUT_BASE = 17
Public Const MM_AMD_INTERWAVE_WAVEOUT_TREBLE = 18
Public Const MM_AMD_INTERWAVE_STEREO_ENHANCED = 19

' MM_COREDYNAMICS product IDs '
Public Const MM_COREDYNAMICS_DYNAMIXHR = 1                ' DynaMax Hi-Rez '
Public Const MM_COREDYNAMICS_DYNASONIX_SYNTH = 2          ' DynaSonix '
Public Const MM_COREDYNAMICS_DYNASONIX_MIDI_IN = 3
Public Const MM_COREDYNAMICS_DYNASONIX_MIDI_OUT = 4
Public Const MM_COREDYNAMICS_DYNASONIX_WAVE_IN = 5
Public Const MM_COREDYNAMICS_DYNASONIX_WAVE_OUT = 6
Public Const MM_COREDYNAMICS_DYNASONIX_AUDIO_IN = 7
Public Const MM_COREDYNAMICS_DYNASONIX_AUDIO_OUT = 8
Public Const MM_COREDYNAMICS_DYNAGRAFX_VGA = 9            ' DynaGrfx '
Public Const MM_COREDYNAMICS_DYNAGRAFX_WAVE_IN = 10
Public Const MM_COREDYNAMICS_DYNAGRAFX_WAVE_OUT = 11

' MM_CANAM product IDs '
Public Const MM_CANAM_CBXWAVEOUT = 1
Public Const MM_CANAM_CBXWAVEIN = 2

' MM_SOFTSOUND product IDs '
Public Const MM_SOFTSOUND_CODEC = 1

' MM_NORRIS product IDs '
Public Const MM_NORRIS_VOICELINK = 1

' MM_DDD product IDs '
Public Const MM_DDD_MIDILINK_MIDIIN = 1
Public Const MM_DDD_MIDILINK_MIDIOUT = 2

' MM_EUPHONICS product IDs '
Public Const MM_EUPHONICS_AUX_CD = 1
Public Const MM_EUPHONICS_AUX_LINE = 2
Public Const MM_EUPHONICS_AUX_MASTER = 3
Public Const MM_EUPHONICS_AUX_MIC = 4
Public Const MM_EUPHONICS_AUX_MIDI = 5
Public Const MM_EUPHONICS_AUX_WAVE = 6
Public Const MM_EUPHONICS_FMSYNTH_MONO = 7
Public Const MM_EUPHONICS_FMSYNTH_STEREO = 8
Public Const MM_EUPHONICS_MIDIIN = 9
Public Const MM_EUPHONICS_MIDIOUT = 10
Public Const MM_EUPHONICS_MIXER = 11
Public Const MM_EUPHONICS_WAVEIN = 12
Public Const MM_EUPHONICS_WAVEOUT = 13
Public Const MM_EUPHONICS_EUSYNTH = 14

' MM_CRYSTAL_NET product IDs '
Public Const CRYSTAL_NET_SFM_CODEC = 1

' MM_CHROMATIC product IDs '
Public Const MM_CHROMATIC_M1 = &H1
Public Const MM_CHROMATIC_M1_WAVEIN = &H2
Public Const MM_CHROMATIC_M1_WAVEOUT = &H3
Public Const MM_CHROMATIC_M1_FMSYNTH = &H4
Public Const MM_CHROMATIC_M1_MIXER = &H5
Public Const MM_CHROMATIC_M1_AUX = &H6
Public Const MM_CHROMATIC_M1_AUX_CD = &H7
Public Const MM_CHROMATIC_M1_MIDIIN = &H8
Public Const MM_CHROMATIC_M1_MIDIOUT = &H9
Public Const MM_CHROMATIC_M1_WTSYNTH = &H10
Public Const MM_CHROMATIC_M1_MPEGWAVEIN = &H11
Public Const MM_CHROMATIC_M1_MPEGWAVEOUT = &H12
Public Const MM_CHROMATIC_M2 = &H13
Public Const MM_CHROMATIC_M2_WAVEIN = &H14
Public Const MM_CHROMATIC_M2_WAVEOUT = &H15
Public Const MM_CHROMATIC_M2_FMSYNTH = &H16
Public Const MM_CHROMATIC_M2_MIXER = &H17
Public Const MM_CHROMATIC_M2_AUX = &H18
Public Const MM_CHROMATIC_M2_AUX_CD = &H19
Public Const MM_CHROMATIC_M2_MIDIIN = &H20
Public Const MM_CHROMATIC_M2_MIDIOUT = &H21
Public Const MM_CHROMATIC_M2_WTSYNTH = &H22
Public Const MM_CHROMATIC_M2_MPEGWAVEIN = &H23
Public Const MM_CHROMATIC_M2_MPEGWAVEOUT = &H24

' MM_VIENNASYS product IDs '
Public Const MM_VIENNASYS_TSP_WAVE_DRIVER = 1

' MM_CONNECTIX product IDs '
Public Const MM_CONNECTIX_VIDEC_CODEC = 1

' MM_GADGETLABS product IDs '
Public Const MM_GADGETLABS_WAVE44_WAVEIN = 1
Public Const MM_GADGETLABS_WAVE44_WAVEOUT = 2
Public Const MM_GADGETLABS_WAVE42_WAVEIN = 3
Public Const MM_GADGETLABS_WAVE42_WAVEOUT = 4
Public Const MM_GADGETLABS_WAVE4_MIDIIN = 5
Public Const MM_GADGETLABS_WAVE4_MIDIOUT = 6

' MM_FRONTIER product IDs '
Public Const MM_FRONTIER_WAVECENTER_MIDIIN = 1            ' WaveCenter '
Public Const MM_FRONTIER_WAVECENTER_MIDIOUT = 2
Public Const MM_FRONTIER_WAVECENTER_WAVEIN = 3
Public Const MM_FRONTIER_WAVECENTER_WAVEOUT = 4

' MM_VIONA product IDs '
Public Const MM_VIONA_QVINPCI_MIXER = 1                   ' Q-Motion PCI II/Bravado 2000 '
Public Const MM_VIONA_QVINPCI_WAVEIN = 2
Public Const MM_VIONAQVINPCI_WAVEOUT = 3
Public Const MM_VIONA_BUSTER_MIXER = 4                    ' Buster '
Public Const MM_VIONA_CINEMASTER_MIXER = 5                ' Cinemaster '
Public Const MM_VIONA_CONCERTO_MIXER = 6                  ' Concerto '

' MM_CASIO product IDs '
Public Const MM_CASIO_WP150_MIDIOUT = 1                   ' wp150 '
Public Const MM_CASIO_WP150_MIDIIN = 2
Public Const MM_CASIO_LSG_MIDIOUT = 3

' MM_DIAMONDMM product IDs '
Public Const MM_DIMD_PLATFORM = 0                         ' Freedom Audio '
Public Const MM_DIMD_DIRSOUND = 1
Public Const MM_DIMD_VIRTMPU = 2
Public Const MM_DIMD_VIRTSB = 3
Public Const MM_DIMD_VIRTJOY = 4
Public Const MM_DIMD_WAVEIN = 5
Public Const MM_DIMD_WAVEOUT = 6
Public Const MM_DIMD_MIDIIN = 7
Public Const MM_DIMD_MIDIOUT = 8
Public Const MM_DIMD_AUX_LINE = 9
Public Const MM_DIMD_MIXER = 10
Public Const MM_DIMD_WSS_WAVEIN = 14
Public Const MM_DIMD_WSS_WAVEOUT = 15
Public Const MM_DIMD_WSS_MIXER = 17
Public Const MM_DIMD_WSS_AUX = 21
Public Const MM_DIMD_WSS_SYNTH = 76

' MM_S3 product IDs '
Public Const MM_S3_WAVEOUT = 1
Public Const MM_S3_WAVEIN = 2
Public Const MM_S3_MIDIOUT = 3
Public Const MM_S3_MIDIIN = 4
Public Const MM_S3_FMSYNTH = 5
Public Const MM_S3_MIXER = 6
Public Const MM_S3_AUX = 7

' MM_VANKOEVERING product IDs '
Public Const MM_VKC_MPU401_MIDIIN = &H100
Public Const MM_VKC_SERIAL_MIDIIN = &H101
Public Const MM_VKC_MPU401_MIDIOUT = &H200
Public Const MM_VKC_SERIAL_MIDIOUT = &H201

' MM_ZEFIRO product IDs '
Public Const MM_ZEFIRO_ZA2 = 2

' MM_FRAUNHOFER_IIS product IDs '
Public Const MM_FHGIIS_MPEGLAYER3 = 10

' MM_QUICKNET product IDs '
Public Const MM_QUICKNET_PJWAVEIN = 1
Public Const MM_QUICKNET_PJWAVEOUT = 2

' MM_SICRESOURCE product IDs '
Public Const MM_SICRESOURCE_SSO3D = 2
Public Const MM_SICRESOURCE_SSOW3DI = 3

' MM_NEOMAGIC product IDs '
Public Const MM_NEOMAGIC_SYNTH = 1
Public Const MM_NEOMAGIC_WAVEOUT = 2
Public Const MM_NEOMAGIC_WAVEIN = 3
Public Const MM_NEOMAGIC_MIDIOUT = 4
Public Const MM_NEOMAGIC_MIDIIN = 5
Public Const MM_NEOMAGIC_AUX = 6
Public Const MM_NEOMAGIC_MW3DX_WAVEOUT = 10
Public Const MM_NEOMAGIC_MW3DX_WAVEIN = 11
Public Const MM_NEOMAGIC_MW3DX_MIDIOUT = 12
Public Const MM_NEOMAGIC_MW3DX_MIDIIN = 13
Public Const MM_NEOMAGIC_MW3DX_FMSYNTH = 14
Public Const MM_NEOMAGIC_MW3DX_GMSYNTH = 15
Public Const MM_NEOMAGIC_MW3DX_MIXER = 16
Public Const MM_NEOMAGIC_MW3DX_AUX = 17
Public Const MM_NEOMAGIC_MWAVE_WAVEOUT = 20
Public Const MM_NEOMAGIC_MWAVE_WAVEIN = 21
Public Const MM_NEOMAGIC_MWAVE_MIDIOUT = 22
Public Const MM_NEOMAGIC_MWAVE_MIDIIN = 23
Public Const MM_NEOMAGIC_MWAVE_MIXER = 24
Public Const MM_NEOMAGIC_MWAVE_AUX = 25

' MM_MERGING_TECHNOLOGIES product IDs '
Public Const MM_MERGING_MPEGL3 = 1

' MM_XIRLINK product IDs '
Public Const MM_XIRLINK_VISIONLINK = 1

' MM_OTI product IDs '
Public Const MM_OTI_611WAVEIN = 5
Public Const MM_OTI_611WAVEOUT = 6
Public Const MM_OTI_611MIXER = 7
Public Const MM_OTI_611MIDIN = &H12
Public Const MM_OTI_611MIDIOUT = &H13

' MM_AUREAL product IDs '
Public Const MM_AUREAL_AU8820 = 16
Public Const MM_AU8820_SYNTH = 17
Public Const MM_AU8820_WAVEOUT = 18
Public Const MM_AU8820_WAVEIN = 19
Public Const MM_AU8820_MIXER = 20
Public Const MM_AU8820_AUX = 21
Public Const MM_AU8820_MIDIOUT = 22
Public Const MM_AU8820_MIDIIN = 23
Public Const MM_AUREAL_AU8830 = 32
Public Const MM_AU8830_SYNTH = 33
Public Const MM_AU8830_WAVEOUT = 34
Public Const MM_AU8830_WAVEIN = 35
Public Const MM_AU8830_MIXER = 36
Public Const MM_AU8830_AUX = 37
Public Const MM_AU8830_MIDIOUT = 38
Public Const MM_AU8830_MIDIIN = 39

' MM_VIVO product IDs '
Public Const MM_VIVO_AUDIO_CODEC = 1

' MM_SHARP product IDs '
Public Const MM_SHARP_MDC_MIDI_SYNTH = 1
Public Const MM_SHARP_MDC_MIDI_IN = 2
Public Const MM_SHARP_MDC_MIDI_OUT = 3
Public Const MM_SHARP_MDC_WAVE_IN = 4
Public Const MM_SHARP_MDC_WAVE_OUT = 5
Public Const MM_SHARP_MDC_AUX = 6
Public Const MM_SHARP_MDC_MIXER = 10
Public Const MM_SHARP_MDC_AUX_MASTER = 100
Public Const MM_SHARP_MDC_AUX_BASS = 101
Public Const MM_SHARP_MDC_AUX_TREBLE = 102
Public Const MM_SHARP_MDC_AUX_MIDI_VOL = 103
Public Const MM_SHARP_MDC_AUX_WAVE_VOL = 104
Public Const MM_SHARP_MDC_AUX_WAVE_RVB = 105
Public Const MM_SHARP_MDC_AUX_WAVE_CHR = 106
Public Const MM_SHARP_MDC_AUX_VOL = 107
Public Const MM_SHARP_MDC_AUX_RVB = 108
Public Const MM_SHARP_MDC_AUX_CHR = 109

' MM_LUCENT product IDs '
Public Const MM_LUCENT_ACM_G723 = 0

' MM_ATT product IDs '
Public Const MM_ATT_G729A = 1

' MM_MARIAN product IDs '
Public Const MM_MARIAN_ARC44WAVEIN = 1
Public Const MM_MARIAN_ARC44WAVEOUT = 2
Public Const MM_MARIAN_PRODIF24WAVEIN = 3
Public Const MM_MARIAN_PRODIF24WAVEOUT = 4
Public Const MM_MARIAN_ARC88WAVEIN = 5
Public Const MM_MARIAN_ARC88WAVEOUT = 6

' MM_BCB product IDs '
Public Const MM_BCB_NETBOARD_10 = 1
Public Const MM_BCB_TT75_10 = 2

' MM_MOTIONPIXELS product IDs '
Public Const MM_MOTIONPIXELS_MVI2 = 1

' MM_QDESIGN product IDs '
Public Const MM_QDESIGN_ACM_MPEG = 1
Public Const MM_QDESIGN_ACM_QDESIGN_MUSIC = 2

' MM_NMP product IDs '
Public Const MM_NMP_CCP_WAVEIN = 1
Public Const MM_NMP_CCP_WAVEOUT = 2
Public Const MM_NMP_ACM_AMR = 10

' MM_DATAFUSION product IDs '
Public Const MM_DF_ACM_G726 = 1
Public Const MM_DF_ACM_GSM610 = 2

' MM_BERCOS product IDs '
Public Const MM_BERCOS_WAVEIN = 1
Public Const MM_BERCOS_MIXER = 2
Public Const MM_BERCOS_WAVEOUT = 3

' MM_ONLIVE product IDs '
Public Const MM_ONLIVE_MPCODEC = 1

' MM_PHONET product IDs '
Public Const MM_PHONET_PP_WAVEOUT = 1
Public Const MM_PHONET_PP_WAVEIN = 2
Public Const MM_PHONET_PP_MIXER = 3

' MM_FTR product IDs '
Public Const MM_FTR_ENCODER_WAVEIN = 1
Public Const MM_FTR_ACM = 2

' MM_ENET product IDs '
Public Const MM_ENET_T2000_LINEIN = 1
Public Const MM_ENET_T2000_LINEOUT = 2
Public Const MM_ENET_T2000_HANDSETIN = 3
Public Const MM_ENET_T2000_HANDSETOUT = 4

'  MM_EMAGIC product IDs '
Public Const MM_EMAGIC_UNITOR8 = 1

'  MM_SIPROLAB product IDs '
Public Const MM_SIPROLAB_ACELPNET = 1

'  MM_DICTAPHONE product IDs '
Public Const MM_DICTAPHONE_G726 = 1                       ' G726 ACM codec (g726pcm.acm) '

'  MM_RZS product IDs '
Public Const MM_RZS_ACM_TUBGSM = 1                       ' GSM 06.10 CODEC '

'  MM_EES product IDs '
Public Const MM_EES_PCMIDI14 = 1
Public Const MM_EES_PCMIDI14_IN = 2
Public Const MM_EES_PCMIDI14_OUT1 = 3
Public Const MM_EES_PCMIDI14_OUT2 = 4
Public Const MM_EES_PCMIDI14_OUT3 = 5
Public Const MM_EES_PCMIDI14_OUT4 = 6

'  MM_HAFTMANN product IDs '
Public Const MM_HAFTMANN_LPTDAC2 = 1

'  MM_LUCID product IDs '
Public Const MM_LUCID_PCI24WAVEIN = 1
Public Const MM_LUCID_PCI24WAVEOUT = 2

'  MM_HEADSPACE product IDs '
Public Const MM_HEADSPACE_HAESYNTH = 1
Public Const MM_HEADSPACE_HAEWAVEOUT = 2
Public Const MM_HEADSPACE_HAEWAVEIN = 3
Public Const MM_HEADSPACE_HAEMIXER = 4

'  MM_UNISYS product IDs '
Public Const MM_UNISYS_ACM_NAP = 1

'  MM_LUMINOSITI product IDs '

Public Const MM_LUMINOSITI_SCWAVEIN = 1
Public Const MM_LUMINOSITI_SCWAVEOUT = 2
Public Const MM_LUMINOSITI_SCWAVEMIX = 3

'  MM_ACTIVEVOICE product IDs '
Public Const MM_ACTIVEVOICE_ACM_VOXADPCM = 1

'  MM_DTS product IDs '
Public Const MM_DTS_DS = 1

'  MM_SOFTLAB_NSK product IDs '
Public Const MM_SOFTLAB_NSK_FRW_WAVEIN = 1
Public Const MM_SOFTLAB_NSK_FRW_WAVEOUT = 2
Public Const MM_SOFTLAB_NSK_FRW_MIXER = 3
Public Const MM_SOFTLAB_NSK_FRW_AUX = 4

'  MM_FORTEMEDIA product IDs '
Public Const MM_FORTEMEDIA_WAVEIN = 1
Public Const MM_FORTEMEDIA_WAVEOUT = 2
Public Const MM_FORTEMEDIA_FMSYNC = 3
Public Const MM_FORTEMEDIA_MIXER = 4
Public Const MM_FORTEMEDIA_AUX = 5

'  MM_SONORUS product IDs '
Public Const MM_SONORUS_STUDIO = 1

'  MM_I_LINK product IDs '
Public Const MM_I_LINK_VOICE_CODER = 1

'  MM_SELSIUS_SYSTEMS product IDs '
Public Const MM_SELSIUS_SYSTEMS_RTPWAVEOUT = 1
Public Const MM_SELSIUS_SYSTEMS_RTPWAVEIN = 2

'  MM_ADMOS product IDs '
Public Const MM_ADMOS_FM_SYNTH = 1
Public Const MM_ADMOS_QS3AMIDIOUT = 2
Public Const MM_ADMOS_QS3AMIDIIN = 3
Public Const MM_ADMOS_QS3AWAVEOUT = 4
Public Const MM_ADMOS_QS3AWAVEIN = 5

' MM_LEXICON product IDs '
Public Const MM_LEXICON_STUDIO_WAVE_OUT = 1
Public Const MM_LEXICON_STUDIO_WAVE_IN = 2

' MM_SGI product IDs '
Public Const MM_SGI_320_WAVEIN = 1
Public Const MM_SGI_320_WAVEOUT = 2
Public Const MM_SGI_320_MIXER = 3
Public Const MM_SGI_540_WAVEIN = 4
Public Const MM_SGI_540_WAVEOUT = 5
Public Const MM_SGI_540_MIXER = 6
Public Const MM_SGI_RAD_ADATMONO1_WAVEIN = 7
Public Const MM_SGI_RAD_ADATMONO2_WAVEIN = 8
Public Const MM_SGI_RAD_ADATMONO3_WAVEIN = 9
Public Const MM_SGI_RAD_ADATMONO4_WAVEIN = 10
Public Const MM_SGI_RAD_ADATMONO5_WAVEIN = 11
Public Const MM_SGI_RAD_ADATMONO6_WAVEIN = 12
Public Const MM_SGI_RAD_ADATMONO7_WAVEIN = 13
Public Const MM_SGI_RAD_ADATMONO8_WAVEIN = 14
Public Const MM_SGI_RAD_ADATSTEREO12_WAVEIN = 15
Public Const MM_SGI_RAD_ADATSTEREO34_WAVEIN = 16
Public Const MM_SGI_RAD_ADATSTEREO56_WAVEIN = 17
Public Const MM_SGI_RAD_ADATSTEREO78_WAVEIN = 18
Public Const MM_SGI_RAD_ADAT8CHAN_WAVEIN = 19
Public Const MM_SGI_RAD_ADATMONO1_WAVEOUT = 20
Public Const MM_SGI_RAD_ADATMONO2_WAVEOUT = 21
Public Const MM_SGI_RAD_ADATMONO3_WAVEOUT = 22
Public Const MM_SGI_RAD_ADATMONO4_WAVEOUT = 23
Public Const MM_SGI_RAD_ADATMONO5_WAVEOUT = 24
Public Const MM_SGI_RAD_ADATMONO6_WAVEOUT = 25
Public Const MM_SGI_RAD_ADATMONO7_WAVEOUT = 26
Public Const MM_SGI_RAD_ADATMONO8_WAVEOUT = 27
Public Const MM_SGI_RAD_ADATSTEREO12_WAVEOUT = 28
Public Const MM_SGI_RAD_ADATSTEREO32_WAVEOUT = 29
Public Const MM_SGI_RAD_ADATSTEREO56_WAVEOUT = 30
Public Const MM_SGI_RAD_ADATSTEREO78_WAVEOUT = 31
Public Const MM_SGI_RAD_ADAT8CHAN_WAVEOUT = 32
Public Const MM_SGI_RAD_AESMONO1_WAVEIN = 33
Public Const MM_SGI_RAD_AESMONO2_WAVEIN = 34
Public Const MM_SGI_RAD_AESSTEREO_WAVEIN = 35
Public Const MM_SGI_RAD_AESMONO1_WAVEOUT = 36
Public Const MM_SGI_RAD_AESMONO2_WAVEOUT = 37
Public Const MM_SGI_RAD_AESSTEREO_WAVEOUT = 38

' MM_IPI product IDs '
Public Const MM_IPI_ACM_HSX = 1
Public Const MM_IPI_ACM_RPELP = 2
Public Const MM_IPI_WF_ASSS = 3
Public Const MM_IPI_AT_WAVEOUT = 4
Public Const MM_IPI_AT_WAVEIN = 5
Public Const MM_IPI_AT_MIXER = 6

' MM_ICE product IDs '
Public Const MM_ICE_WAVEOUT = 1
Public Const MM_ICE_WAVEIN = 2
Public Const MM_ICE_MTWAVEOUT = 3
Public Const MM_ICE_MTWAVEIN = 4
Public Const MM_ICE_MIDIOUT1 = 5
Public Const MM_ICE_MIDIIN1 = 6
Public Const MM_ICE_MIDIOUT2 = 7
Public Const MM_ICE_MIDIIN2 = 8
Public Const MM_ICE_SYNTH = 9
Public Const MM_ICE_MIXER = 10
Public Const MM_ICE_AUX = 11

' MM_VQST product IDs '
Public Const MM_VQST_VQC1 = 1
Public Const MM_VQST_VQC2 = 2

' MM_ETEK product IDs '
Public Const MM_ETEK_KWIKMIDI_MIDIIN = 1
Public Const MM_ETEK_KWIKMIDI_MIDIOUT = 2

' MM_INTERNET product IDs '
Public Const MM_INTERNET_SSW_MIDIOUT = 10
Public Const MM_INTERNET_SSW_MIDIIN = 11
Public Const MM_INTERNET_SSW_WAVEOUT = 12
Public Const MM_INTERNET_SSW_WAVEIN = 13

' MM_SONY product IDs '
Public Const MM_SONY_ACM_SCX = 1

' MM_UHER_INFORMATIC product IDs '
Public Const MM_UH_ACM_ADPCM = 1

' MM_SYDEC_NV product IDs '
Public Const MM_SYDEC_NV_WAVEIN = 1
Public Const MM_SYDEC_NV_WAVEOUT = 2

' MM_FLEXION product IDs '
Public Const MM_FLEXION_X300_WAVEIN = 1
Public Const MM_FLEXION_X300_WAVEOUT = 2

' MM_VIA product IDs '
Public Const MM_VIA_WAVEOUT = 1
Public Const MM_VIA_WAVEIN = 2
Public Const MM_VIA_MIXER = 3
Public Const MM_VIA_AUX = 4
Public Const MM_VIA_MPU401_MIDIOUT = 5
Public Const MM_VIA_MPU401_MIDIIN = 6
Public Const MM_VIA_SWFM_SYNTH = 7
Public Const MM_VIA_WDM_WAVEOUT = 8
Public Const MM_VIA_WDM_WAVEIN = 9
Public Const MM_VIA_WDM_MIXER = 10
Public Const MM_VIA_WDM_MPU401_MIDIOUT = 11
Public Const MM_VIA_WDM_MPU401_MIDIIN = 12

' MM_MICRONAS product IDs '
Public Const MM_MICRONAS_SC4 = 1
Public Const MM_MICRONAS_CLP833 = 2

' MM_HP product IDs '
Public Const MM_HP_WAVEOUT = 1
Public Const MM_HP_WAVEIN = 2

' MM_QUICKAUDIO product IDs '
Public Const MM_QUICKAUDIO_MINIMIDI = 1
Public Const MM_QUICKAUDIO_MAXIMIDI = 2

' MM_ICCC product IDs '
Public Const MM_ICCC_UNA3_WAVEIN = 1
Public Const MM_ICCC_UNA3_WAVEOUT = 2
Public Const MM_ICCC_UNA3_AUX = 3
Public Const MM_ICCC_UNA3_MIXER = 4

' MM_3COM product IDs '
Public Const MM_3COM_CB_MIXER = 1
Public Const MM_3COM_CB_WAVEIN = 2
Public Const MM_3COM_CB_WAVEOUT = 3

' MM_MINDMAKER product IDs '
Public Const MM_MINDMAKER_GC_WAVEIN = 1
Public Const MM_MINDMAKER_GC_WAVEOUT = 2
Public Const MM_MINDMAKER_GC_MIXER = 3

' MM_TELEKOL product IDs '
Public Const MM_TELEKOL_WAVEOUT = 1
Public Const MM_TELEKOL_WAVEIN = 2

' MM_ALGOVISION product IDs '
Public Const MM_ALGOVISION_VB80WAVEOUT = 1
Public Const MM_ALGOVISION_VB80WAVEIN = 2
Public Const MM_ALGOVISION_VB80MIXER = 3
Public Const MM_ALGOVISION_VB80AUX = 4
Public Const MM_ALGOVISION_VB80AUX2 = 5


' ------------------------------------------------------------------------------ '

'              INFO LIST CHUNKS (from the Multimedia Programmer's Reference
'


Public Const WAVE_FORMAT_UNKNOWN = &H0                       ' Microsoft Corporation '
Public Const WAVE_FORMAT_ADPCM = &H2                         ' Microsoft Corporation '
Public Const WAVE_FORMAT_IEEE_FLOAT = &H3                    ' Microsoft Corporation '
Public Const WAVE_FORMAT_VSELP = &H4                         ' Compaq Computer Corp. '
Public Const WAVE_FORMAT_IBM_CVSD = &H5                      ' IBM Corporation '
Public Const WAVE_FORMAT_ALAW = &H6                          ' Microsoft Corporation '
Public Const WAVE_FORMAT_MULAW = &H7                         ' Microsoft Corporation '
Public Const WAVE_FORMAT_DTS = &H8                           ' Microsoft Corporation '
Public Const WAVE_FORMAT_DRM = &H9                           ' Microsoft Corporation '
Public Const WAVE_FORMAT_OKI_ADPCM = &H10                    ' OKI '
Public Const WAVE_FORMAT_DVI_ADPCM = &H11                    ' Intel Corporation '
Public Const WAVE_FORMAT_IMA_ADPCM = (WAVE_FORMAT_DVI_ADPCM)                  '  Intel Corporation '
Public Const WAVE_FORMAT_MEDIASPACE_ADPCM = &H12             ' Videologic '
Public Const WAVE_FORMAT_SIERRA_ADPCM = &H13                 ' Sierra Semiconductor Corp '
Public Const WAVE_FORMAT_G723_ADPCM = &H14                   ' Antex Electronics Corporation '
Public Const WAVE_FORMAT_DIGISTD = &H15                      ' DSP Solutions, Inc. '
Public Const WAVE_FORMAT_DIGIFIX = &H16                      ' DSP Solutions, Inc. '
Public Const WAVE_FORMAT_DIALOGIC_OKI_ADPCM = &H17           ' Dialogic Corporation '
Public Const WAVE_FORMAT_MEDIAVISION_ADPCM = &H18            ' Media Vision, Inc. '
Public Const WAVE_FORMAT_CU_CODEC = &H19                     ' Hewlett-Packard Company '
Public Const WAVE_FORMAT_YAMAHA_ADPCM = &H20                 ' Yamaha Corporation of America '
Public Const WAVE_FORMAT_SONARC = &H21                       ' Speech Compression '
Public Const WAVE_FORMAT_DSPGROUP_TRUESPEECH = &H22          ' DSP Group, Inc '
Public Const WAVE_FORMAT_ECHOSC1 = &H23                      ' Echo Speech Corporation '
Public Const WAVE_FORMAT_AUDIOFILE_AF36 = &H24               ' Virtual Music, Inc. '
Public Const WAVE_FORMAT_APTX = &H25                         ' Audio Processing Technology '
Public Const WAVE_FORMAT_AUDIOFILE_AF10 = &H26               ' Virtual Music, Inc. '
Public Const WAVE_FORMAT_PROSODY_1612 = &H27                 ' Aculab plc '
Public Const WAVE_FORMAT_LRC = &H28                          ' Merging Technologies S.A. '
Public Const WAVE_FORMAT_DOLBY_AC2 = &H30                    ' Dolby Laboratories '
Public Const WAVE_FORMAT_GSM610 = &H31                       ' Microsoft Corporation '
Public Const WAVE_FORMAT_MSNAUDIO = &H32                     ' Microsoft Corporation '
Public Const WAVE_FORMAT_ANTEX_ADPCME = &H33                 ' Antex Electronics Corporation '
Public Const WAVE_FORMAT_CONTROL_RES_VQLPC = &H34            ' Control Resources Limited '
Public Const WAVE_FORMAT_DIGIREAL = &H35                     ' DSP Solutions, Inc. '
Public Const WAVE_FORMAT_DIGIADPCM = &H36                    ' DSP Solutions, Inc. '
Public Const WAVE_FORMAT_CONTROL_RES_CR10 = &H37             ' Control Resources Limited '
Public Const WAVE_FORMAT_NMS_VBXADPCM = &H38                 ' Natural MicroSystems '
Public Const WAVE_FORMAT_CS_IMAADPCM = &H39                  ' Crystal Semiconductor IMA ADPCM '
Public Const WAVE_FORMAT_ECHOSC3 = &H3A                      ' Echo Speech Corporation '
Public Const WAVE_FORMAT_ROCKWELL_ADPCM = &H3B               ' Rockwell International '
Public Const WAVE_FORMAT_ROCKWELL_DIGITALK = &H3C            ' Rockwell International '
Public Const WAVE_FORMAT_XEBEC = &H3D                        ' Xebec Multimedia Solutions Limited '
Public Const WAVE_FORMAT_G721_ADPCM = &H40                   ' Antex Electronics Corporation '
Public Const WAVE_FORMAT_G728_CELP = &H41                    ' Antex Electronics Corporation '
Public Const WAVE_FORMAT_MSG723 = &H42                       ' Microsoft Corporation '
Public Const WAVE_FORMAT_MPEG = &H50                         ' Microsoft Corporation '
Public Const WAVE_FORMAT_RT24 = &H52                         ' InSoft, Inc. '
Public Const WAVE_FORMAT_PAC = &H53                          ' InSoft, Inc. '
Public Const WAVE_FORMAT_MPEGLAYER3 = &H55                   ' ISO/MPEG Layer3 Format Tag '
Public Const WAVE_FORMAT_LUCENT_G723 = &H59                  ' Lucent Technologies '
Public Const WAVE_FORMAT_CIRRUS = &H60                       ' Cirrus Logic '
Public Const WAVE_FORMAT_ESPCM = &H61                        ' ESS Technology '
Public Const WAVE_FORMAT_VOXWARE = &H62                      ' Voxware Inc '
Public Const WAVE_FORMAT_CANOPUS_ATRAC = &H63                ' Canopus, co., Ltd. '
Public Const WAVE_FORMAT_G726_ADPCM = &H64                   ' APICOM '
Public Const WAVE_FORMAT_G722_ADPCM = &H65                   ' APICOM '
Public Const WAVE_FORMAT_DSAT_DISPLAY = &H67                 ' Microsoft Corporation '
Public Const WAVE_FORMAT_VOXWARE_BYTE_ALIGNED = &H69         ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_AC8 = &H70                  ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_AC10 = &H71                 ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_AC16 = &H72                 ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_AC20 = &H73                 ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_RT24 = &H74                 ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_RT29 = &H75                 ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_RT29HW = &H76               ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_VR12 = &H77                 ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_VR18 = &H78                 ' Voxware Inc '
Public Const WAVE_FORMAT_VOXWARE_TQ40 = &H79                 ' Voxware Inc '
Public Const WAVE_FORMAT_SOFTSOUND = &H80                    ' Softsound, Ltd. '
Public Const WAVE_FORMAT_VOXWARE_TQ60 = &H81                 ' Voxware Inc '
Public Const WAVE_FORMAT_MSRT24 = &H82                       ' Microsoft Corporation '
Public Const WAVE_FORMAT_G729A = &H83                        ' AT&T Labs, Inc. '
Public Const WAVE_FORMAT_MVI_MVI2 = &H84                     ' Motion Pixels '
Public Const WAVE_FORMAT_DF_G726 = &H85                      ' DataFusion Systems (Pty) (Ltd) '
Public Const WAVE_FORMAT_DF_GSM610 = &H86                    ' DataFusion Systems (Pty) (Ltd) '
Public Const WAVE_FORMAT_ISIAUDIO = &H88                     ' Iterated Systems, Inc. '
Public Const WAVE_FORMAT_ONLIVE = &H89                       ' OnLive! Technologies, Inc. '
Public Const WAVE_FORMAT_SBC24 = &H91                        ' Siemens Business Communications Sys '
Public Const WAVE_FORMAT_DOLBY_AC3_SPDIF = &H92              ' Sonic Foundry '
Public Const WAVE_FORMAT_MEDIASONIC_G723 = &H93              ' MediaSonic '
Public Const WAVE_FORMAT_PROSODY_8KBPS = &H94                ' Aculab plc '
Public Const WAVE_FORMAT_ZYXEL_ADPCM = &H97                  ' ZyXEL Communications, Inc. '
Public Const WAVE_FORMAT_PHILIPS_LPCBB = &H98                ' Philips Speech Processing '
Public Const WAVE_FORMAT_PACKED = &H99                       ' Studer Professional Audio AG '
Public Const WAVE_FORMAT_MALDEN_PHONYTALK = &HA0             ' Malden Electronics Ltd. '
Public Const WAVE_FORMAT_RHETOREX_ADPCM = &H100              ' Rhetorex Inc. '
Public Const WAVE_FORMAT_IRAT = &H101                        ' BeCubed Software Inc. '
Public Const WAVE_FORMAT_VIVO_G723 = &H111                   ' Vivo Software '
Public Const WAVE_FORMAT_VIVO_SIREN = &H112                  ' Vivo Software '
Public Const WAVE_FORMAT_DIGITAL_G723 = &H123                ' Digital Equipment Corporation '
Public Const WAVE_FORMAT_SANYO_LD_ADPCM = &H125              ' Sanyo Electric Co., Ltd. '
Public Const WAVE_FORMAT_SIPROLAB_ACEPLNET = &H130           ' Sipro Lab Telecom Inc. '
Public Const WAVE_FORMAT_SIPROLAB_ACELP4800 = &H131          ' Sipro Lab Telecom Inc. '
Public Const WAVE_FORMAT_SIPROLAB_ACELP8V3 = &H132           ' Sipro Lab Telecom Inc. '
Public Const WAVE_FORMAT_SIPROLAB_G729 = &H133               ' Sipro Lab Telecom Inc. '
Public Const WAVE_FORMAT_SIPROLAB_G729A = &H134              ' Sipro Lab Telecom Inc. '
Public Const WAVE_FORMAT_SIPROLAB_KELVIN = &H135             ' Sipro Lab Telecom Inc. '
Public Const WAVE_FORMAT_G726ADPCM = &H140                   ' Dictaphone Corporation '
Public Const WAVE_FORMAT_QUALCOMM_PUREVOICE = &H150          ' Qualcomm, Inc. '
Public Const WAVE_FORMAT_QUALCOMM_HALFRATE = &H151           ' Qualcomm, Inc. '
Public Const WAVE_FORMAT_TUBGSM = &H155                      ' Ring Zero Systems, Inc. '
Public Const WAVE_FORMAT_MSAUDIO1 = &H160                    ' Microsoft Corporation '
Public Const WAVE_FORMAT_UNISYS_NAP_ADPCM = &H170            ' Unisys Corp. '
Public Const WAVE_FORMAT_UNISYS_NAP_ULAW = &H171             ' Unisys Corp. '
Public Const WAVE_FORMAT_UNISYS_NAP_ALAW = &H172             ' Unisys Corp. '
Public Const WAVE_FORMAT_UNISYS_NAP_16K = &H173              ' Unisys Corp. '
Public Const WAVE_FORMAT_CREATIVE_ADPCM = &H200              ' Creative Labs, Inc '
Public Const WAVE_FORMAT_CREATIVE_FASTSPEECH8 = &H202        ' Creative Labs, Inc '
Public Const WAVE_FORMAT_CREATIVE_FASTSPEECH10 = &H203       ' Creative Labs, Inc '
Public Const WAVE_FORMAT_UHER_ADPCM = &H210                  ' UHER informatic GmbH '
Public Const WAVE_FORMAT_QUARTERDECK = &H220                 ' Quarterdeck Corporation '
Public Const WAVE_FORMAT_ILINK_VC = &H230                    ' I-link Worldwide '
Public Const WAVE_FORMAT_RAW_SPORT = &H240                   ' Aureal Semiconductor '
Public Const WAVE_FORMAT_ESST_AC3 = &H241                    ' ESS Technology, Inc. '
Public Const WAVE_FORMAT_IPI_HSX = &H250                     ' Interactive Products, Inc. '
Public Const WAVE_FORMAT_IPI_RPELP = &H251                   ' Interactive Products, Inc. '
Public Const WAVE_FORMAT_CS2 = &H260                         ' Consistent Software '
Public Const WAVE_FORMAT_SONY_SCX = &H270                    ' Sony Corp. '
Public Const WAVE_FORMAT_FM_TOWNS_SND = &H300                ' Fujitsu Corp. '
Public Const WAVE_FORMAT_BTV_DIGITAL = &H400                 ' Brooktree Corporation '
Public Const WAVE_FORMAT_QDESIGN_MUSIC = &H450               ' QDesign Corporation '
Public Const WAVE_FORMAT_VME_VMPCM = &H680                   ' AT&T Labs, Inc. '
Public Const WAVE_FORMAT_TPC = &H681                         ' AT&T Labs, Inc. '
Public Const WAVE_FORMAT_OLIGSM = &H1000                     ' Ing C. Olivetti & C., S.p.A. '
Public Const WAVE_FORMAT_OLIADPCM = &H1001                   ' Ing C. Olivetti & C., S.p.A. '
Public Const WAVE_FORMAT_OLICELP = &H1002                    ' Ing C. Olivetti & C., S.p.A. '
Public Const WAVE_FORMAT_OLISBC = &H1003                     ' Ing C. Olivetti & C., S.p.A. '
Public Const WAVE_FORMAT_OLIOPR = &H1004                     ' Ing C. Olivetti & C., S.p.A. '
Public Const WAVE_FORMAT_LH_CODEC = &H1100                   ' Lernout & Hauspie '
Public Const WAVE_FORMAT_NORRIS = &H1400                     ' Norris Communications, Inc. '
Public Const WAVE_FORMAT_SOUNDSPACE_MUSICOMPRESS = &H1500    ' AT&T Labs, Inc. '
Public Const WAVE_FORMAT_DVM = &H2000                        ' FAST Multimedia AG '


Public Const SPEAKER_FRONT_LEFT = &H1
Public Const SPEAKER_FRONT_RIGHT = &H2
Public Const SPEAKER_FRONT_CENTER = &H4
Public Const SPEAKER_LOW_FREQUENCY = &H8
Public Const SPEAKER_BACK_LEFT = &H10
Public Const SPEAKER_BACK_RIGHT = &H20
Public Const SPEAKER_FRONT_LEFT_OF_CENTER = &H40
Public Const SPEAKER_FRONT_RIGHT_OF_CENTER = &H80
Public Const SPEAKER_BACK_CENTER = &H100
Public Const SPEAKER_SIDE_LEFT = &H200
Public Const SPEAKER_SIDE_RIGHT = &H400
Public Const SPEAKER_TOP_CENTER = &H800
Public Const SPEAKER_TOP_FRONT_LEFT = &H1000
Public Const SPEAKER_TOP_FRONT_CENTER = &H2000
Public Const SPEAKER_TOP_FRONT_RIGHT = &H4000
Public Const SPEAKER_TOP_BACK_LEFT = &H8000
Public Const SPEAKER_TOP_BACK_CENTER = &H10000
Public Const SPEAKER_TOP_BACK_RIGHT = &H20000

' Bit mask locations reserved for future use
Public Const SPEAKER_RESERVED = &H7FFC0000

' Used to specify that any possible permutation of speaker configurations
Public Const SPEAKER_ALL = &H80000000



Public Const JIFMK_SOF0 = &HFFC0       ' SOF Huff  - Baseline DCT'
Public Const JIFMK_SOF1 = &HFFC1       ' SOF Huff  - Extended sequential DCT'
Public Const JIFMK_SOF2 = &HFFC2       ' SOF Huff  - Progressive DCT'
Public Const JIFMK_SOF3 = &HFFC3       ' SOF Huff  - Spatial (sequential) lossless'
Public Const JIFMK_SOF5 = &HFFC5       ' SOF Huff  - Differential sequential DCT'
Public Const JIFMK_SOF6 = &HFFC6       ' SOF Huff  - Differential progressive DCT'
Public Const JIFMK_SOF7 = &HFFC7       ' SOF Huff  - Differential spatial'
Public Const JIFMK_JPG = &HFFC8        ' SOF Arith - Reserved for JPEG extensions'
Public Const JIFMK_SOF9 = &HFFC9       ' SOF Arith - Extended sequential DCT'
Public Const JIFMK_SOF10 = &HFFCA      ' SOF Arith - Progressive DCT'
Public Const JIFMK_SOF11 = &HFFCB      ' SOF Arith - Spatial (sequential) lossless'
Public Const JIFMK_SOF13 = &HFFCD      ' SOF Arith - Differential sequential DCT'
Public Const JIFMK_SOF14 = &HFFCE      ' SOF Arith - Differential progressive DCT'
Public Const JIFMK_SOF15 = &HFFCF      ' SOF Arith - Differential spatial'
Public Const JIFMK_DHT = &HFFC4        ' Define Huffman Table(s) '
Public Const JIFMK_DAC = &HFFCC        ' Define Arithmetic coding conditioning(s) '
Public Const JIFMK_RST0 = &HFFD0       ' Restart with modulo 8 count 0 '
Public Const JIFMK_RST1 = &HFFD1       ' Restart with modulo 8 count 1 '
Public Const JIFMK_RST2 = &HFFD2       ' Restart with modulo 8 count 2 '
Public Const JIFMK_RST3 = &HFFD3       ' Restart with modulo 8 count 3 '
Public Const JIFMK_RST4 = &HFFD4       ' Restart with modulo 8 count 4 '
Public Const JIFMK_RST5 = &HFFD5       ' Restart with modulo 8 count 5 '
Public Const JIFMK_RST6 = &HFFD6       ' Restart with modulo 8 count 6 '
Public Const JIFMK_RST7 = &HFFD7       ' Restart with modulo 8 count 7 '
Public Const JIFMK_SOI = &HFFD8        ' Start of Image '
Public Const JIFMK_EOI = &HFFD9        ' End of Image '
Public Const JIFMK_SOS = &HFFDA        ' Start of Scan '
Public Const JIFMK_DQT = &HFFDB        ' Define quantization Table(s) '
Public Const JIFMK_DNL = &HFFDC        ' Define Number of Lines '
Public Const JIFMK_DRI = &HFFDD        ' Define Restart Interval '
Public Const JIFMK_DHP = &HFFDE        ' Define Hierarchical progression '
Public Const JIFMK_EXP = &HFFDF        ' Expand Reference Component(s) '
Public Const JIFMK_APP0 = &HFFE0       ' Application Field 0'
Public Const JIFMK_APP1 = &HFFE1       ' Application Field 1'
Public Const JIFMK_APP2 = &HFFE2       ' Application Field 2'
Public Const JIFMK_APP3 = &HFFE3       ' Application Field 3'
Public Const JIFMK_APP4 = &HFFE4       ' Application Field 4'
Public Const JIFMK_APP5 = &HFFE5       ' Application Field 5'
Public Const JIFMK_APP6 = &HFFE6       ' Application Field 6'
Public Const JIFMK_APP7 = &HFFE7       ' Application Field 7'
Public Const JIFMK_JPG0 = &HFFF0       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG1 = &HFFF1       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG2 = &HFFF2       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG3 = &HFFF3       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG4 = &HFFF4       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG5 = &HFFF5       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG6 = &HFFF6       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG7 = &HFFF7       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG8 = &HFFF8       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG9 = &HFFF9       ' Reserved for JPEG extensions '
Public Const JIFMK_JPG10 = &HFFFA      ' Reserved for JPEG extensions '
Public Const JIFMK_JPG11 = &HFFFB      ' Reserved for JPEG extensions '
Public Const JIFMK_JPG12 = &HFFFC      ' Reserved for JPEG extensions '
Public Const JIFMK_JPG13 = &HFFFD      ' Reserved for JPEG extensions '
Public Const JIFMK_COM = &HFFFE        ' Comment '
Public Const JIFMK_TEM = &HFF01        ' for temp private use arith code '
Public Const JIFMK_RES = &HFF02        ' Reserved '
Public Const JIFMK_00 = &HFF00         ' Zero stuffed byte - entropy data '
Public Const JIFMK_FF = &HFFFF         ' Fill byte '

' JPEGColorSpaceID Definitions '
Public Const JPEG_Y = 1                 ' Y only component of YCbCr '
Public Const JPEG_YCbCr = 2             ' YCbCr as define by CCIR 601 '
Public Const JPEG_RGB = 3               ' 3 component RGB '
