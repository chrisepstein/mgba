/* Copyright (c) 2013-2016 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef M_CORE_SYNC_H
#define M_CORE_SYNC_H

#include "util/common.h"

#include "util/threading.h"

struct mCoreSync {
	int videoFramePending;
	bool videoFrameWait;
	bool videoFrameOn;
	Mutex videoFrameMutex;
	Condition videoFrameAvailableCond;
	Condition videoFrameRequiredCond;

	bool audioWait;
	Condition audioRequiredCond;
	Mutex audioBufferMutex;

	float fpsTarget;
};

void mCoreSyncPostFrame(struct mCoreSync* sync);
void mCoreSyncForceFrame(struct mCoreSync* sync);
bool mCoreSyncWaitFrameStart(struct mCoreSync* sync);
void mCoreSyncWaitFrameEnd(struct mCoreSync* sync);
void mCoreSyncSetVideoSync(struct mCoreSync* sync, bool wait);

void mCoreSyncProduceAudio(struct mCoreSync* sync, bool wait);
void mCoreSyncLockAudio(struct mCoreSync* sync);
void mCoreSyncUnlockAudio(struct mCoreSync* sync);
void mCoreSyncConsumeAudio(struct mCoreSync* sync);

#endif
