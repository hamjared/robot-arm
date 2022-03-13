import { TestBed } from '@angular/core/testing';

import { RobotArmService } from './robot-arm.service';
import { MessageService } from './message.service';

describe('RobotArmService', () => {
  let service: RobotArmService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(RobotArmService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
