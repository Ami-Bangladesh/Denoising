# Denoising
Noise remove from an image applying Denoising using OpenCV C++

Denoising:
Denoising or noise reduction is the process of removing noise from signals obtained
from analog or digital devices. This section focuses its attention on reducing noise
from digital images and videos.
Although smoothing and median filtering are good options to denoise an image,
OpenCV provides other algorithms to perform this task. These are the nonlocal
means and the TVL1 (Total Variation L1) algorithms. The basic idea of the nonlocal
means algorithm is to replace the color of a pixel with an average of the colors from
several image sub-windows that are similar to the one that comprises the pixel
neighborhood. On the other hand, the TVL1 variational denoising model, which
is implemented with the primal-dual optimization algorithm, considers the
image-denoising process a variational problem.

OpenCV provides four functions to denoise color and grayscale images following
the nonlocal means approach. For the TVL1 model, one function is provided. These
functions are:

• void fastNlMeansDenoising(InputArray src, OutputArray dst,
float h = 3, int templateWindowSize = 7, int searchWindowSize
= 21): This denoises a single grayscale image loaded in src. The
templateWindowSize and searchWindowSize parameters are the sizes
in pixels of the template patch that is used to compute weights and the
window that is used to compute the weighted average for the given pixel.
These should be odd and their recommended values are 7 and 21 pixels,
respectively. The h parameter regulates the effect of the algorithm. Larger h
values remove more noise defects but with the drawback of removing more
image details. The output is stored in dst.

• void fastNlMeansDenoisingColored(InputArray src, OutputArray
dst, float h = 3, float hForColorComponents = 3, int
templateWindowSize = 7, int searchWindowSize = 21): This is a
modification of the previous function for colored images. It converts the src
image to the CIELAB color space and then separately denoises the L and AB
components with the fastNlMeansDenoising function.

• void fastNlMeansDenoisingMulti(InputArrayOfArrays srcImgs,
OutputArray dst, int imgToDenoiseIndex, int temporalWindowSize,
float h = 3, int templateWindowSize = 7, int searchWindowSize
= 21): This uses an image sequence to obtain a denoised image. Two
more parameters are needed in this case: imgToDenoiseIndex and
temporalWindowSize. The value of imgToDenoiseIndex is the target image
index in srcImgs to be denoised. Finally, temporalWindowSize is used to
establish the number of surrounding images to be used for denoising. This
should be odd.

• void fastNlMeansDenoisingColoredMulti(InputArrayOfArrays srcImgs, OutputArray dst, int imgToDenoiseIndex, int
temporalWindowSize, float h = 3, float hForColorComponents
= 3, int templateWindowSize = 7, int searchWindowSize
= 21): This is based on the fastNlMeansDenoisingColored and
fastNlMeansDenoisingMulti functions. The parameters are explained in
the rest of the functions.

• void denoise_TVL1(const std::vector<Mat>& observations, Mat&
result, double lambda, int niters): This obtains a denoised image in
result from one or more noisy images stored in observations. The lambda
and niters parameters control the strength and the number of iterations of
the algorithm.
