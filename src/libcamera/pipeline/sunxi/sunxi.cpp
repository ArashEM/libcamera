/**
 * @file sunxi.cpp
 * @author Arash Golgol (arash.golgol@gmail.com)
 * @brief Pipeline handler for Allwinner SoC
 * @version 1.0
 * @date 2025-06-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <memory>

#include <libcamera/base/log.h>
#include <libcamera/camera.h>

#include "libcamera/internal/pipeline_handler.h"


namespace libcamera {

LOG_DEFINE_CATEGORY(SUNXI)

class PipelineHandlerSunxi : public PipelineHandler
{
public:
	PipelineHandlerSunxi(CameraManager *manager);

	std::unique_ptr<CameraConfiguration> generateConfiguration(Camera *camera,
								   Span<const StreamRole> roles) override;
	int configure(Camera *camera, CameraConfiguration *config) override;

	int exportFrameBuffers(Camera *camera, Stream *stream,
			       std::vector<std::unique_ptr<FrameBuffer>> *buffers) override;

	int start(Camera *camera, const ControlList *controls) override;
	void stopDevice(Camera *camera) override;

	int queueRequestDevice(Camera *camera, Request *request) override;

	bool match(DeviceEnumerator *enumerator) override;
};

PipelineHandlerSunxi::PipelineHandlerSunxi(CameraManager *manager)
	: PipelineHandler(manager)
{
}

std::unique_ptr<CameraConfiguration> PipelineHandlerSunxi::generateConfiguration(Camera *camera,
										 Span<const StreamRole> roles)
{
	(void)camera;
	(void)roles;
	return nullptr;
}

int PipelineHandlerSunxi::configure(Camera *camera, CameraConfiguration *config)
{
	(void)camera;
	(void)config;
	return -1;
}

int PipelineHandlerSunxi::exportFrameBuffers(Camera *camera, Stream *stream,
					     std::vector<std::unique_ptr<FrameBuffer>> *buffers)
{
	(void)camera;
	(void)stream;
	(void)buffers;
	return -1;
}

int PipelineHandlerSunxi::start(Camera *camera, const ControlList *controls)
{
	(void)camera;
	(void)controls;
	return -1;
}

void PipelineHandlerSunxi::stopDevice(Camera *camera)
{
	(void)camera;
}

int PipelineHandlerSunxi::queueRequestDevice(Camera *camera, Request *request)
{
	(void)camera;
	(void)request;
	return -1;
}

bool PipelineHandlerSunxi::match(DeviceEnumerator *enumerator)
{
	(void)enumerator;
	return false;
}

REGISTER_PIPELINE_HANDLER(PipelineHandlerSunxi, "sunxi")

} // namespace libcamera
