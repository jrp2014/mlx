// Copyright © 2025 Apple Inc.

#pragma once

#include <memory>

#include "jaccl/group.h"

namespace jaccl {

/**
 * Check if JACCL (RDMA over Thunderbolt) is available on this system.
 */
bool is_available();

/**
 * Initialize a JACCL communication group.
 *
 * Reads configuration from environment variables:
 *   - JACCL_RANK / MLX_RANK: The rank of this process
 *   - JACCL_IBV_DEVICES / MLX_IBV_DEVICES: Path to the device connectivity JSON
 * file
 *   - JACCL_COORDINATOR / MLX_JACCL_COORDINATOR: IP:port of the coordinator
 *   - JACCL_RING / MLX_JACCL_RING: If set, prefer ring topology
 *
 * Args:
 *   strict: If true, throw on failure. If false, return nullptr.
 *
 * Returns:
 *   A shared_ptr to the Group, or nullptr on failure.
 */
std::shared_ptr<Group> init(bool strict = false);

} // namespace jaccl
