ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = gstd gst-client

gstd_SOURCES = gstd-interfaces.vala gstd-main.vala gstd-factory.vala gstd-pipeline.vala gstd-signals.vala
gstd_VALAFLAGS = --thread @EXTRA_VAPIDIR@ --vapidir=. --pkg gstd-config \
    --pkg gio-2.0 --pkg gstreamer-1.0 --pkg gstreamer-base-1.0 \
	--pkg gstreamer-video-1.0 --pkg posix \
    @GSTREAMER_SUPPORT_QOS_SIGNAL@ @GSTREAMER_SUPPORT_STEP@ @GSTD_SUPPORT_SIGNALS@
gstd_CFLAGS = @GSTREAMER_CFLAGS@ @GIO_CFLAGS@
gstd_LDADD = @GSTREAMER_LIBS@ @GIO_LIBS@

gst_client_SOURCES = gstd-interfaces.vala gst-client.vala
gst_client_VALAFLAGS = @EXTRA_VAPIDIR@ --vapidir=. --pkg gstd-config \
    --pkg gio-2.0 --pkg gstreamer-1.0 --pkg gstreamer-base-1.0 \
	--pkg gstreamer-video-1.0 --pkg posix \
    @READLINE_SUPPORT@
gst_client_CFLAGS = @GSTREAMER_CFLAGS@
gst_client_LDADD = @GSTREAMER_LIBS@ @GIO_LIBS@ @READLINE_LIBS@

install-data-hook:
	cd $(DESTDIR)$(bindir) ; rm -f gst-client-interpreter ; $(LN_S) gst-client gst-client-interpreter

interfaces_xml := com.ridgerun.gstreamer.gstd.FactoryInterface.xml \
 com.ridgerun.gstreamer.gstd.PipelineInterface.xml

EXTRA_DIST= $(interfaces_xml)

interfacedir=$(datadir)/dbus-1/interfaces/
interface_DATA= $(interfaces_xml)
