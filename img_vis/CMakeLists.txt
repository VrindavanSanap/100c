list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
add_executable(img_vis main.c)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(img_vis PRIVATE 
    SDL2::SDL2 
    SDL2_image::SDL2_image
)

add_custom_command(
	TARGET img_vis POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/images
	$<TARGET_FILE_DIR:img_vis>/images
	COMMENT "Copying images to build output"
)